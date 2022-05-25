#include "RawSocketCommunicator.h"

#include <evpp/tcp_server.h>
#include <evpp/timestamp.h>

#include "SpdLogger.h"

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

        evpp::Buffer* response;
        switch (request->request_type())
        {
        case Seeder::RequestType_HelloRequest:
            response = handle_hello_request(conn, request->request_as_HelloRequest());
            break;
        case Seeder::RequestType_GetPeersRequest:
            response = handle_get_peers_request(conn, request->request_as_GetPeersRequest());
            break;
        default:
            break;
        }

        conn->Send(response);
        delete response;
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

evpp::Buffer* RawSocketCommunicator::handle_hello_request(const evpp::TCPConnPtr& conn,
    const Seeder::HelloRequest* request)
{
    evpp::Buffer* response = new evpp::Buffer();
    if (client_manager->add({ "1.2.2.3" }))       // Added successfully
    {
        response->AppendInt8(1);
    }
    else {
        response->AppendInt8(0);
    }

    return response;
}

evpp::Buffer* RawSocketCommunicator::handle_get_peers_request(const evpp::TCPConnPtr& conn,
    const Seeder::GetPeersRequest* request)
{
	throw std::logic_error("The method or operation is not implemented.");
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
