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
	/// Add new client to client manager. @return true if succeeds
	bool add(Client&& client)
	{
		return database.add_client(std::move(client));
	}

	/// Remove a client from the manager.
	void remove(const std::string& address)
	{
		database.remove_client(address);
	}

	/// @return number of existing clients
	size_t count() const noexcept
	{
		return database.get_clients_count();
	}

	/// @return @c count number of peers sorted by scoring method.
	std::vector<SharedClient> get_elited_peers(size_t count)
	{
		return database.get_elited_peers(count);
	}

	/// Touch a client and update its alive timestamp.
	void touch(const std::string& address, time_t alive_timestamp)
	{
		database.touch_client(address, alive_timestamp);
	}

	/// @return alive clients alive since @c since
	std::vector<SharedClient> get_alive_peers_since(time_t since)
	{
		return database.get_alive_peers_since(since);
	}

	/// Change the number of connections of a client.
	void set_number_of_connections_of(const std::string& address, size_t n)
	{
		return database.set_number_of_connections_of(address, n);
	}

private:
	 Database database;
};

typedef ClientManager<InMemoryDatabase> InMemoryClientManager;

#endif // ClientManager_h__
