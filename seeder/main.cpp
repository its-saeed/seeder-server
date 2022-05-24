#include "ArgumentParser.h"
#include "SeederService.h"

int main(int argc, char** argv)
{
    ArgumentParser argument_parser(argc, argv);
    Argument arguments = argument_parser.parse();
    SeederService service(arguments);
    service.start();
    return 0;
}
