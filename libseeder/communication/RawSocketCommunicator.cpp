#include "RawSocketCommunicator.h"

#include <evpp/tcp_server.h>
#include <evpp/tcp_conn.h>
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
        client_manager->add({"1.2.2.3"});
        auto request = parse_buffer(msg);
        logging::log()->info("New request of type {}", request->request_type());

        conn->Send(msg);
    });
    server.SetConnectionCallback([](const evpp::TCPConnPtr& conn) {
        if (conn->IsConnected()) {
        } else {
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