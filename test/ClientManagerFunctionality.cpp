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

TEST_CASE("getting first 3 clients based on last alive should return correct ones", "[clients]") {
	logging::init();
	ClientManager<InMemoryCollection> client_manager;
	client_manager.add({ "1.2.3.1" });
	client_manager.add({ "1.2.3.2" });
	client_manager.add({ "1.2.3.3" });
	client_manager.add({ "1.2.3.4" });
	client_manager.add({ "1.2.3.5" });

	client_manager.touch("1.2.3.1", 10);
	client_manager.touch("1.2.3.2", 2);
	client_manager.touch("1.2.3.3", 3);
	client_manager.touch("1.2.3.4", 30);
	client_manager.touch("1.2.3.5", 6);

	auto nodes = client_manager.get_active_nodes(3);

	REQUIRE("1.2.3.4" == nodes[0]->get_address());
	REQUIRE("1.2.3.1" == nodes[1]->get_address());
	REQUIRE("1.2.3.5" == nodes[2]->get_address());
}

TEST_CASE("getting clients which are alive since a specific time should return them", "[clients]") {
	logging::init();
	ClientManager<InMemoryCollection> client_manager;
	client_manager.add({ "1.2.3.1" });
	client_manager.add({ "1.2.3.2" });
	client_manager.add({ "1.2.3.3" });
	client_manager.add({ "1.2.3.4" });
	client_manager.add({ "1.2.3.5" });

	client_manager.touch("1.2.3.1", 10);
	client_manager.touch("1.2.3.2", 2);
	client_manager.touch("1.2.3.3", 3);
	client_manager.touch("1.2.3.4", 30);
	client_manager.touch("1.2.3.5", 6);

	auto nodes = client_manager.get_alive_nodes_since(10);

	REQUIRE("1.2.3.4" == nodes[0]->get_address());
	REQUIRE("1.2.3.1" == nodes[1]->get_address());
}