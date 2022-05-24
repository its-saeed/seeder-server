#include "ArgumentParser.h"
#include "SeederService.h"
#include "logger/SpdLogger.h"

int main(int argc, char** argv)
{
    logging::init();
    ArgumentParser argument_parser(argc, argv);
    Argument arguments = argument_parser.parse();
    SeederService service(arguments);
    service.start();
    return 0;
}
