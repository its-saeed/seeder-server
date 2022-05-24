add_library(libseeder argument-parser/ArgumentParser.cpp
		client-manager/ClientManager.cpp
		SeederService.cpp "communication/RawSocketCommunicator.h" "database/InMemoryPersistor.h" "client-manager/Client.h" "database/InMemoryPersistor.cpp")

target_include_directories(libseeder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/argument-parser
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/database
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/communication
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/logger)
