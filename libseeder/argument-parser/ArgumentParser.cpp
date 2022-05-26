#include "ArgumentParser.h"
#include "cxxopts.hpp"

Argument ArgumentParser::parse(int argc, const char** argv)
{
	Argument arguments;
	cxxopts::Options options("Seeder", "Zilliqa Home Test Application");
	options.add_options()
		("p,port", "Start of UDP Port of the server", cxxopts::value<int>())
		("g,ping", "Ping interval of the clients (in seconds)", cxxopts::value<int>())
		("h,help", "Print usage")
		;
	auto result = options.parse(argc, argv);
	if (result.count("help"))
	{
		std::cout << options.help() << std::endl;
		exit(0);
	}

	if (result.count("port"))
		arguments.beginning_port = result["port"].as<int>();
	else
		arguments.beginning_port = Argument::DEFAULT_PORT;


	if (result.count("ping"))
		arguments.client_ping_interval = std::chrono::seconds(result["ping"].as<int>());
	else
		arguments.client_ping_interval = Argument::DEFAULT_PING;

	return arguments;
}

