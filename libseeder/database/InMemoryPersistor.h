#ifndef InMemoryPersistor_h__
#define InMemoryPersistor_h__

#include "Persistor.h"

#include <unordered_map>
#include "../client-manager/Client.h"

class InMemoryPersistor : public Persistor
{
public:
	void add_client(Client&& client) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	void remove_client(const Client& client) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	void touch_client(const Client& client) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

private:
	std::unordered_map<std::string, Client> active_clients;
};

#endif // InMemoryPersistor_h__
