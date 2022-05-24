#ifndef InMemoryPersistor_h__
#define InMemoryPersistor_h__

#include <unordered_map>

#include "Client.h"

class InMemoryCollection 
{
public:
	void add_client(Client&& client);
	void remove_client(const std::string& address);
	void touch_client(const std::string& client);
	size_t get_clients_count() const noexcept;

private:
	std::unordered_map<std::string, Client> active_clients;
};

#endif // InMemoryPersistor_h__
