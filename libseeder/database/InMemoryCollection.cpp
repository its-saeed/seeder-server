#include "InMemoryCollection.h"
#include "SpdLogger.h"

bool InMemoryCollection::add_client(Client&& client)
{
	if (active_clients.find(client.get_address()) != active_clients.end())
	{
		logging::log()->warn("Trying to add an existing client with address {}", client.get_address());
		return false;
	}

	active_clients.insert(std::make_pair(client.get_address(), std::move(client)));
	return true;
}

void InMemoryCollection::remove_client(const std::string& address)
{
	if (active_clients.find(address) == active_clients.end())
	{
		logging::log()->warn("Trying to remove a non-existing client with address {}", address);
		return;
	}

	active_clients.erase(address);
}

void InMemoryCollection::touch_client(const std::string& address)
{
	throw std::logic_error("The method or operation is not implemented.");
}

size_t InMemoryCollection::get_clients_count() const noexcept
{
	return active_clients.size();
}

std::vector<std::string> InMemoryCollection::get_active_clients(int count)
{
	// TODO: Consider performance here.
	int added = 0;
	std::vector<std::string> active;
	for (auto const& [key, val] : active_clients)
	{
		active.push_back(key);
	}

	return active;
}
