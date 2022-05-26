#ifndef ArgumentParser_h__
#define ArgumentParser_h__

#include <chrono>

struct Argument
{
	static constexpr uint16_t DEFAULT_PORT = 9099;
	static constexpr std::chrono::seconds DEFAULT_PING = std::chrono::seconds(5);

	std::chrono::seconds client_ping_interval;
	uint16_t beginning_port;
};

class ArgumentParser
{
public:
	ArgumentParser() = delete;
	ArgumentParser(const ArgumentParser& other) = delete;
	ArgumentParser(ArgumentParser&& other) = delete;

	static Argument parse(int argc, const char** argv);
};

#endif // ArgumentParser_h__

