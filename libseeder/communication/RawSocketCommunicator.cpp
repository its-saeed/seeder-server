#include "RawSocketCommunicator.h"

#include <evpp/tcp_server.h>
#include <evpp/timestamp.h>

#include "SpdLogger.h"
#include "Response_generated.h"

RawSocketCommunicator::RawSocketCommunicator(InMemoryClientManager* client_manager)
: client_manager(client_manager)
{
}

void RawSocketCommunicator::run()
{
    std::string addr = "0.0.0.0:9099";
    int thread_num = 4;
    evpp::EventLoop loop;
    evpp::TCPServer server(&loop, addr, "Seeder Tcp Server", thread_num);
    server.SetMessageCallback([this](const evpp::TCPConnPtr& conn,
                                 evpp::Buffer* msg) {
        // TODO: Handle concurrency
        
        auto request = parse_buffer(msg);
        logging::log()->info("New request of type {} with ID {}",
            request_type_to_string(request->request_type()), request->id());

        switch (request->request_type())
        {
        case Seeder::RequestType_HelloRequest:
            handle_hello_request(conn, request);
            break;
        case Seeder::RequestType_GetPeersRequest:
            handle_get_peers_request(conn, request);
            break;
        default:
            break;
        }
    });
    server.SetConnectionCallback([](const evpp::TCPConnPtr& conn) {
        if (conn->IsConnected()) {
            logging::log()->info("new connection from {}", conn->AddrToString());
        } else {
            logging::log()->info("disconnected from {}", conn->AddrToString());
        }
    });
    server.Init();
    if (server.Start())
        logging::log()->info("TCP Server started successfully...");
    else{
        logging::log()->critical("Failed to start TCP server.");
        exit(EXIT_FAILURE);
    }
    loop.Run();
}

const Seeder::Request* RawSocketCommunicator::parse_buffer(evpp::Buffer* buffer)
{
    const uint16_t incoming_data_size = buffer->ReadInt16();
    const char* data = buffer->data();

    return Seeder::GetRequest(data);
}

void RawSocketCommunicator::handle_hello_request(const evpp::TCPConnPtr& conn,
    const Seeder::Request* request)
{
    flatbuffers::FlatBufferBuilder builder(100);
    flatbuffers::Offset<Seeder::HelloResponse> response;
    if (client_manager->add({ request->request_as_HelloRequest()->address()->str() }))       // Added successfully
        response = Seeder::CreateHelloResponse(builder, Seeder::HelloRequestResult::HelloRequestResult_REGISTERED_SUCCESSFULLY);
    else
        response = Seeder::CreateHelloResponse(builder, Seeder::HelloRequestResult::HelloRequestResult_ALREADY_REGISTERED);

    auto response_builder = Seeder::ResponseBuilder(builder);
    response_builder.add_id(request->id());

    response_builder.add_response(response.Union());
    response_builder.add_response_type(Seeder::ResponseType_HelloResponse);

	auto orc = response_builder.Finish();
	builder.Finish(orc);
	const uint8_t* buffer = builder.GetBufferPointer();
	const size_t size = builder.GetSize();

    conn->Send(buffer, size);
}

void RawSocketCommunicator::handle_get_peers_request(const evpp::TCPConnPtr& conn,
    const Seeder::Request* request)
{
    flatbuffers::FlatBufferBuilder builder(1000);

    const auto peers = client_manager->get_active_nodes(request->request_as_GetPeersRequest()->number_of_peers());

    std::vector<flatbuffers::Offset<flatbuffers::String>> active_peers;
    for (const auto& peer : peers) {
        active_peers.push_back(builder.CreateString(peer));
    }
    auto response = Seeder::CreateGetPeersResponse(builder, builder.CreateVector(active_peers));

    auto response_builder = Seeder::ResponseBuilder(builder);
    response_builder.add_id(request->id());
    response_builder.add_response(response.Union());
    response_builder.add_response_type(Seeder::ResponseType_GetPeersResponse);

	auto orc = response_builder.Finish();
	builder.Finish(orc);
	const uint8_t* buffer = builder.GetBufferPointer();
	const size_t size = builder.GetSize();

    conn->Send(buffer, size);
}

std::string RawSocketCommunicator::request_type_to_string(Seeder::RequestType request_type)
{
    switch (request_type)
    {
    case Seeder::RequestType_HelloRequest:
        return "HELLO";
    case Seeder::RequestType_PingRequest:
        return "PING";
    case Seeder::RequestType_GetPeersRequest:
        return "GET_PEERS";
        break;
    case Seeder::RequestType_NONE:
    default:
        break;
    }

    return "INVALID";
}
