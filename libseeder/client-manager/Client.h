#ifndef Client_h__
#define Client_h__

#include <string>

class Client
{
public:
	const std::string& get_address() const noexcept
	{
		return address;
	}

private:
	std::string address;
};

#endif // Client_h__
