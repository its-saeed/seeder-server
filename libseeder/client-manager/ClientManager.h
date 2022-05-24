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
	void add(Client&& client)
	{
		logging::log()->info("Client {} added to Client manager.", client.get_address());
		persistor.add_client(std::move(client));
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

	std::vector<Client> get_active_nodes(int count);

private:
	Persistor persistor;
};

typedef ClientManager<InMemoryCollection> InMemoryClientManager;

#endif // ClientManager_h__
