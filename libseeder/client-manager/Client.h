#ifndef Client_h__
#define Client_h__

#include <string>

class Client
{
public:
	Client(std::string&& address)
	: address(std::move(address))
	{
	}

	const std::string& get_address() const noexcept
	{
		return address;
	}

private:
	std::string address;
};

#endif // Client_h__
