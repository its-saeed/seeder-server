#ifndef InMemoryPersistor_h__
#define InMemoryPersistor_h__

#include "Persistor.h"

#include <unordered_map>
#include "../client-manager/Client.h"

class InMemoryPersistor : public Persistor
{
public:
	void add_client(Client&& client) override;
	void remove_client(const std::string& address) override;
	void touch_client(const std::string& client) override;
	size_t get_clients_count() const noexcept override;

private:
	std::unordered_map<std::string, Client> active_clients;
};

#endif // InMemoryPersistor_h__
