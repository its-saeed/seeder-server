#ifndef ArgumentParser_h__
#define ArgumentParser_h__

struct Argument
{
	int number_of_threads;
	int client_alive_check_interval;
};

class ArgumentParser
{
public:
	ArgumentParser(int argc, char** argv);
	Argument parse();
};

#endif // ArgumentParser_h__

