#include "ArgumentParser.h"
#include "SeederService.h"
#include "logger/SpdLogger.h"
#include "communication/RawSocketCommunicator.h"
#include "database/InMemoryCollection.h"

int main(int argc, char** argv)
{
    logging::init();
    ArgumentParser argument_parser(argc, argv);
    Argument arguments = argument_parser.parse();
    SeederService<InMemoryCollection, RawSocketCommunicator> service(arguments);
    service.start();
    return 0;
}
