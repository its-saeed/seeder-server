#ifndef InMemoryPersistor_h__
#define InMemoryPersistor_h__

#include <unordered_map>
#include <vector>

#include "Client.h"

class InMemoryCollection 
{
public:
	bool add_client(Client&& client);
	void remove_client(const std::string& address);
	void touch_client(const std::string& client);
	size_t get_clients_count() const noexcept;
	std::vector<std::string> get_active_clients(int count);

private:
	std::unordered_map<std::string, Client> active_clients;
};

#endif // InMemoryPersistor_h__
