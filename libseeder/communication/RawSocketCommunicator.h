#ifndef RawSocketCommunicator_h__
#define RawSocketCommunicator_h__

#include <evpp/buffer.h>
#include <evpp/tcp_conn.h>

#include "Thread.h"
#include "ClientManager.h"
#include "Request_generated.h"

class RawSocketCommunicator : public Thread
{
public:
	RawSocketCommunicator(InMemoryClientManager* client_manager);
	void run() override;

private:
	static std::string request_type_to_string(Seeder::RequestType request_type);
	const Seeder::Request* parse_buffer(evpp::Buffer* buffer);
	evpp::Buffer* handle_hello_request(const evpp::TCPConnPtr& conn, const Seeder::HelloRequest* request);
	evpp::Buffer* handle_get_peers_request(const evpp::TCPConnPtr& conn, const Seeder::GetPeersRequest* request);

	InMemoryClientManager* client_manager;
};

#endif // RawSocketCommunicator_h__
