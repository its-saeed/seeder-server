#ifndef ClientManager_h__
#define ClientManager_h__

#include <vector>

#include "Client.h"
#include "InMemoryCollection.h"
#include "SpdLogger.h"

template <typename Persistor>
class ClientManager
{
public:
	bool add(Client&& client)
	{
		return persistor.add_client(std::move(client));
	}

	void remove(const std::string& address)
	{
		logging::log()->info("Client {} removed from Client manager.", address);
		persistor.remove_client(address);
	}

	size_t count() const noexcept
	{
		return persistor.get_clients_count();
	}

	std::vector<SharedClient> get_active_nodes(size_t count)
	{
		return persistor.get_active_clients(count);
	}

	void touch(const std::string& address, time_t alive_timestamp)
	{
		persistor.touch_client(address, alive_timestamp);
	}

	std::vector<SharedClient> get_alive_nodes_since(time_t since)
	{
		return persistor.get_alive_nodes_since(since);
	}

private:
	Persistor persistor;
};

typedef ClientManager<InMemoryCollection> InMemoryClientManager;

#endif // ClientManager_h__
