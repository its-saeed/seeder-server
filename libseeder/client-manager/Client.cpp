#include "Client.h"

bool LastAliveCompare::operator()(const SharedClient& client1, const SharedClient& client2) const
{
	return client1->get_last_alive() > client2->get_last_alive();
}
