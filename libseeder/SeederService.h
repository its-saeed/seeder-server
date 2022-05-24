#ifndef SeederService_h__
#define SeederService_h__

#include "ArgumentParser.h"
#include "ClientManager.h"

template<typename CommunicationChannel>
class SeederService
{
public:
	SeederService(Argument arguments)
	: communication_channel(&client_manager)
	{
	}

	void start()
	{
    	communication_channel.start();
		communication_channel.join();
	}

private:
	InMemoryClientManager client_manager;
	CommunicationChannel communication_channel;
};

#endif // SeederService_h__
