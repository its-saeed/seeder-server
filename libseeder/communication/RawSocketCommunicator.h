#ifndef RawSocketCommunicator_h__
#define RawSocketCommunicator_h__

#include <evpp/buffer.h>

#include "Thread.h"
#include "ClientManager.h"
#include "Request_generated.h"

class RawSocketCommunicator : public Thread
{
public:
	RawSocketCommunicator(InMemoryClientManager* client_manager);
	void run() override;

private:
	const Seeder::Request* parse_buffer(evpp::Buffer* buffer);
	InMemoryClientManager* client_manager;
};

#endif // RawSocketCommunicator_h__
