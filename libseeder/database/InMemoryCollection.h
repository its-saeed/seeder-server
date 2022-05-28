#ifndef InMemoryPersistor_h__
#define InMemoryPersistor_h__

#include <unordered_map>
#include <vector>
#include <set>

#include "Client.h"

class InMemoryCollection 
{
public:
	bool add_client(Client&& client);
	void remove_client(const std::string& address);
	void touch_client(const std::string& client, time_t alive_timestamp);
	size_t get_clients_count() const noexcept;
	std::vector<SharedClient> get_active_clients(size_t count);
	std::vector<SharedClient> get_alive_nodes_since(time_t since);

private:
	std::unordered_map<std::string, SharedClient> active_clients;
	LastAliveOrderedClientSet last_alive_ordered_client_set;
};

#endif // InMemoryPersistor_h__
