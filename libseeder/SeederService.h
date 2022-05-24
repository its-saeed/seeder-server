#ifndef SeederService_h__
#define SeederService_h__

#include "argument-parser/ArgumentParser.h"
#include "client-manager/ClientManager.h"

template<typename ClientCollection, typename CommunicationChannel>
class SeederService
{
public:
	SeederService(Argument arguments)
	{
	}

	void start()
	{
    	communication_channel.start();
	}

private:
	ClientManager<ClientCollection> client_manager;
	CommunicationChannel communication_channel;
};

#endif // SeederService_h__
