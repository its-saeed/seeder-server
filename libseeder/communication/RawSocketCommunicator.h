#ifndef RawSocketCommunicator_h__
#define RawSocketCommunicator_h__

#include "Thread.h"
#include "ClientManager.h"

class RawSocketCommunicator : public Thread
{
public:
	RawSocketCommunicator(InMemoryClientManager* client_manager);
	void run() override;

private:
	InMemoryClientManager* client_manager;
};

#endif // RawSocketCommunicator_h__
