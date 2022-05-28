#ifndef ClientManager_h__
#define ClientManager_h__

#include <vector>

#include "Client.h"
#include "InMemoryDatabase.h"
#include "SpdLogger.h"

template <typename Database>
class ClientManager
{
public:
	bool add(Client&& client)
	{
		return database.add_client(std::move(client));
	}

	void remove(const std::string& address)
	{
		logging::log()->info("Client {} removed from Client manager.", address);
		database.remove_client(address);
	}

	size_t count() const noexcept
	{
		return database.get_clients_count();
	}

	std::vector<SharedClient> get_active_nodes(size_t count)
	{
		return database.get_active_clients(count);
	}

	void touch(const std::string& address, time_t alive_timestamp)
	{
		database.touch_client(address, alive_timestamp);
	}

	std::vector<SharedClient> get_alive_peers_since(time_t since)
	{
		return database.get_alive_peers_since(since);
	}

private:
	 Database database;
};

typedef ClientManager<InMemoryDatabase> InMemoryClientManager;

#endif // ClientManager_h__
