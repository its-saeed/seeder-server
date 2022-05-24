#include "gtest/gtest.h"
#include "client-manager/ClientManager.h"
#include "database/InMemoryCollection.h"

class ClientManagerFunctionality : public ::testing::Test
{
protected:
	ClientManager<InMemoryCollection> client_manager;
};

TEST_F(ClientManagerFunctionality, adding_a_new_client_should_increment_clients_count)
{
	client_manager.add({ "1.2.3.4" });
	EXPECT_EQ(1, client_manager.count());
}

TEST_F(ClientManagerFunctionality, removing_a_client_from_the_manager_should_decrement_clients_count)
{
	client_manager.add({ "1.2.3.4" });
	EXPECT_EQ(1, client_manager.count());
	client_manager.remove("1.2.3.4");
	EXPECT_EQ(0, client_manager.count());
}