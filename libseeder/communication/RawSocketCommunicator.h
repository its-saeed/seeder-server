#ifndef RawSocketCommunicator_h__
#define RawSocketCommunicator_h__

#include "../utils/Thread.h"
#include "client-manager/ClientManager.h"

class RawSocketCommunicator : public Thread
{
public:
	RawSocketCommunicator(InMemoryClientManager* client_manager);
	void run() override;

private:
	InMemoryClientManager* client_manager;
};

#endif // RawSocketCommunicator_h__
