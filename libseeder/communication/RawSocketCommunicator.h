#ifndef RawSocketCommunicator_h__
#define RawSocketCommunicator_h__

#include <evpp/udp/udp_message.h>

#include "Thread.h"
#include "ClientManager.h"
#include "ArgumentParser.h"
#include "Request_generated.h"

class RawSocketCommunicator : public Thread
{
public:
	RawSocketCommunicator(InMemoryClientManager* client_manager, const Argument& args);
	void run() override;

private:
	static std::string request_type_to_string(Seeder::RequestType request_type);
	const Seeder::Request* parse_datagram(evpp::udp::MessagePtr& msg);
	void handle_hello_request(const Seeder::Request* request, evpp::udp::MessagePtr& msg);
	void handle_get_peers_request(const Seeder::Request* request, evpp::udp::MessagePtr& msg);
	void handle_peer_status_request(const Seeder::Request* request, evpp::udp::MessagePtr& msg);
	void handle_bye_request(const Seeder::Request* request, evpp::udp::MessagePtr& msg);

	uint16_t beginning_port;
	std::chrono::seconds peer_availability_interval;
	InMemoryClientManager* client_manager;
};

#endif // RawSocketCommunicator_h__
