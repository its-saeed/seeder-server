#include "ArgumentParser.h"
#include "SeederService.h"
#include "logger/SpdLogger.h"
#include "communication/RawSocketCommunicator.h"

int main(int argc, const char** argv)
{
    logging::init();
    Argument arguments = ArgumentParser::parse(argc, argv);
    SeederService<RawSocketCommunicator> service(arguments);
    service.start();
    return 0;
}
