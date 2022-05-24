#ifndef SeederService_h__
#define SeederService_h__

#include "argument-parser/ArgumentParser.h"
#include "client-manager/ClientManager.h"
#include "database/InMemoryCollection.h"

class SeederService
{
public:
	SeederService(Argument arguments);
	void start();

private:
	ClientManager<InMemoryCollection> client_manager;
};

#endif // SeederService_h__
