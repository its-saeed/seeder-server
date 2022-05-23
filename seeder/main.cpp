#include "ArgumentParser.h"

int main(int argc, char** argv)
{
    ArgumentParser argument_parser(argc, argv);
    argument_parser.parse();
    return 0;
}
