#include "RawSocketCommunicator.h"

#include <evpp/tcp_server.h>
#include <evpp/buffer.h>
#include <evpp/tcp_conn.h>
#include <evpp/timestamp.h>

void RawSocketCommunicator::run()
{
    std::string addr = "0.0.0.0:9099";
    int thread_num = 4;
    evpp::EventLoop loop;
    evpp::TCPServer server(&loop, addr, "Seeder Tcp Server", thread_num);
    server.SetMessageCallback([](const evpp::TCPConnPtr& conn,
                                 evpp::Buffer* msg) {
        conn->Send(msg);
    });
    server.SetConnectionCallback([](const evpp::TCPConnPtr& conn) {
        if (conn->IsConnected()) {
            LOG_INFO << "A new connection from " << conn->remote_addr();
        } else {
            LOG_INFO << "Lost the connection from " << conn->remote_addr();
        }
    });
    server.Init();
    server.Start();
    loop.Run();
}