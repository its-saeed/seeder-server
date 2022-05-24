#ifndef Persistor_h__
#define Persistor_h__

#include "client-manager/Client.h"

class Persistor {
public:
	/// Adds new client to the database
	virtual void add_client(Client&& client) = 0;

	/// <summary>
	///  Remove a client from the database
	/// </summary>
	virtual void remove_client(const std::string& address) = 0;

	/// <summary>
	/// Touch a Client. It means the client is alive and active in the network.
	/// </summary>
	virtual void touch_client(const std::string& address) = 0;

	virtual size_t get_clients_count() const noexcept = 0;
};

#endif // Persistor_h__
