#ifndef Client_h__
#define Client_h__

#include <string>
#include <memory>
#include <set>
#include <assert.h>

class Client;

typedef std::shared_ptr<Client> SharedClient;

struct LastAliveCompare {
	bool operator() (const SharedClient& client1, const SharedClient& client2) const;
};

typedef std::multiset<SharedClient, LastAliveCompare> LastAliveOrderedClientSet;

struct ElitedClientCompare {
	bool operator() (const SharedClient& client1, const SharedClient& client2) const;
};

typedef std::multiset<SharedClient, ElitedClientCompare> EliteClientSet;

class Client
{
public:
	Client(std::string&& address)
	: address(std::move(address))
	, last_alive(time(0))
	, number_of_connections(0)
	{
	}

	/// @return address of the client.
	const std::string& get_address() const noexcept
	{
		return address;
	}

	/// @return last alive of the client.
	uint64_t get_last_alive() const noexcept
	{
		return last_alive;
	}

	/// set the last alive of the client.
	void set_last_alive(uint64_t alive) noexcept
	{
		this->last_alive = alive;
	}

	/// set the number of connections of this client.
	void set_number_of_connections(size_t n) noexcept
	{
		number_of_connections = n;
	}

	/// @return number of connections of the client.
	size_t get_number_of_connections() const noexcept
	{
		return number_of_connections;
	}

	EliteClientSet::iterator get_elite_set_inserted_at_iterator() const { return elite_set_inserted_at_iterator; }
	void set_elite_set_inserted_at_iterator(EliteClientSet::iterator val) { elite_set_inserted_at_iterator = val; }
	LastAliveOrderedClientSet::iterator get_last_alive_set_inserted_at_iterator() const
	{
		return last_alive_set_inserted_at_iterator;
	}

	void set_last_alive_set_inserted_at_iterator(LastAliveOrderedClientSet::iterator val)
	{
		last_alive_set_inserted_at_iterator = val;
	}

private:
	std::string address;
	time_t last_alive;
	size_t number_of_connections;

	// Used to make updating last alive timestamp and reordering of the related set more performant.
	LastAliveOrderedClientSet::iterator last_alive_set_inserted_at_iterator;

	// Used to make updating eliteness and reordering of the related set more performant.
	EliteClientSet::iterator elite_set_inserted_at_iterator;
};

#endif // Client_h__
