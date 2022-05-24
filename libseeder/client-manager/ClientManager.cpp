#include "ClientManager.h"

void ClientManager::add(Client&& client)
{
	persistor->add_client(std::move(client));
}

void ClientManager::remove(const std::string& address)
{
	persistor->remove_client(address);
}

size_t ClientManager::count() const noexcept
{
	return persistor->get_clients_count();
}

