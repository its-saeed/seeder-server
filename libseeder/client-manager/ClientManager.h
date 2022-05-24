#ifndef ClientManager_h__
#define ClientManager_h__

#include <vector>

#include "Client.h"

template <typename Persistor>
class ClientManager
{
public:
	void add(Client&& client)
	{
		persistor.add_client(std::move(client));
	}

	void remove(const std::string& address)
	{
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

#endif // ClientManager_h__
