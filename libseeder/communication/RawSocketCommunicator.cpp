#include "RawSocketCommunicator.h"

#include <evpp/tcp_server.h>
#include <evpp/buffer.h>
#include <evpp/tcp_conn.h>
#include <evpp/timestamp.h>

#include "logger/SpdLogger.h"

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
        // Handle concurrency
        client_manager->add({"1.2.2.3"});
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