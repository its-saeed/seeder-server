#include "ArgumentParser.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("if arguments contain port, it should be extracted", "[args]") {
	const char* args[2] = {
		"program-path",
		"--port=1234"
	};
	Argument argument = ArgumentParser::parse(2, args);
	REQUIRE(1234 == argument.beginning_port);
}

TEST_CASE("if arguments contain ping duration, it should be extracted", "[args]") {
	const char* args[2] = {
		"program-path",
		"--ping=5"
	};
	Argument argument = ArgumentParser::parse(2, args);
	REQUIRE(std::chrono::seconds(5) == argument.client_ping_interval);
}

TEST_CASE("if arguments does not contain port, it should be default value", "[args]") {
	const char* args[2] = {
		"program-path",
		"--ping=1"
	};
	Argument argument = ArgumentParser::parse(2, args);
	REQUIRE(Argument::DEFAULT_PORT == argument.beginning_port);
}

TEST_CASE("if argument does not contain ping duration, it should be default value", "[args]") {
	const char* args[2] = {
		"program-path",
		"--port=1"
	};
	Argument argument = ArgumentParser::parse(2, args);
	REQUIRE(Argument::DEFAULT_PING == argument.client_ping_interval);
}
