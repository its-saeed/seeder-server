#include "InMemoryPersistor.h"
#include "logger/SpdLogger.h"

void InMemoryPersistor::add_client(Client&& client)
{
	if (active_clients.find(client.get_address()) != active_clients.end())
	{
		logging::log()->warn("Trying to add an existing client with address {}", client.get_address());
		return;
	}

	active_clients.insert(std::make_pair(client.get_address(), std::move(client)));
}

void InMemoryPersistor::remove_client(const std::string& address)
{
	if (active_clients.find(address) == active_clients.end())
	{
		logging::log()->warn("Trying to remove a non-existing client with address {}", address);
		return;
	}

	active_clients.erase(address);
}

void InMemoryPersistor::touch_client(const std::string& address)
{
	throw std::logic_error("The method or operation is not implemented.");
}

size_t InMemoryPersistor::get_clients_count() const noexcept
{
	return active_clients.size();
}
