#ifndef InMemoryPersistor_h__
#define InMemoryPersistor_h__

#include <unordered_map>
#include <vector>
#include <set>

#include "Client.h"

class InMemoryDatabase 
{
public:
	bool add_client(Client&& client);
	void remove_client(const std::string& address);
	void touch_client(const std::string& client, time_t alive_timestamp);
	size_t get_clients_count() const noexcept;
	std::vector<SharedClient> get_elited_peers(size_t count);
	std::vector<SharedClient> get_alive_peers_since(time_t since);
	void set_number_of_connections_of(const std::string& address, size_t n);

private:
	std::unordered_map<std::string, SharedClient> active_clients;
	LastAliveOrderedClientSet last_alive_ordered_client_set;
	ElitedClientSet elite_client_set;
};

#endif // InMemoryPersistor_h__
