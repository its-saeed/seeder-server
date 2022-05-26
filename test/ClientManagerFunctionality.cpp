#include "ClientManager.h"
#include "database/InMemoryCollection.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Adding a new client should increment clients count", "[clients]") {
	logging::init();
	ClientManager<InMemoryCollection> client_manager;
	client_manager.add({ "1.2.3.4" });
	REQUIRE(1 == 1);
}

TEST_CASE("removing a client from manager should decrement count", "[clients]") {
	logging::init();
	ClientManager<InMemoryCollection> client_manager;
	client_manager.add({ "1.2.3.4" });
	REQUIRE(1 == client_manager.count());
	client_manager.remove("1.2.3.4");
	REQUIRE(0 == client_manager.count());
}