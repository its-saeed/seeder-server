#ifndef Client_h__
#define Client_h__

#include <string>
#include <memory>
#include <set>

class Client;

typedef std::shared_ptr<Client> SharedClient;
struct LastAliveCompare {
	bool operator() (const SharedClient& client1, const SharedClient& client2) const;
};

typedef std::multiset<SharedClient, LastAliveCompare> LastAliveOrderedClientSet;

class Client
{
public:
	Client(std::string&& address)
	: address(std::move(address))
	, last_alive(time(0))
	{
	}

	const std::string& get_address() const noexcept
	{
		return address;
	}

	uint64_t get_last_alive() const noexcept
	{
		return last_alive;
	}

	void set_last_alive(uint64_t alive) noexcept
	{
		this->last_alive = alive;
	}

	LastAliveOrderedClientSet::iterator get_inserted_at_iterator() const { return inserted_at; }
	void set_inserted_at_iterator(LastAliveOrderedClientSet::iterator val) { inserted_at = val; }
private:
	std::string address;
	time_t last_alive;
	LastAliveOrderedClientSet::iterator inserted_at;
};

#endif // Client_h__
