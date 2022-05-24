#include "ArgumentParser.h"
#include "SeederService.h"
#include "logger/SpdLogger.h"
#include "communication/RawSocketCommunicator.h"

int main(int argc, char** argv)
{
    logging::init();
    ArgumentParser argument_parser(argc, argv);
    Argument arguments = argument_parser.parse();
    SeederService<RawSocketCommunicator> service(arguments);
    service.start();
    return 0;
}
