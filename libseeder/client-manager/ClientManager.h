#ifndef ClientManager_h__
#define ClientManager_h__

#include <vector>

#include "../database/Persistor.h"
#include "Client.h"

class ClientManager
{
public:
	void add(Client&& client);
	void remove(const Client& client);
	std::vector<Client> get_active_nodes(int count);

private:
	// TODO: change it to template parameter
	Persistor* persistor;
};

#endif // ClientManager_h__
