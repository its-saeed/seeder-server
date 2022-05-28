add_library(libseeder argument-parser/ArgumentParser.cpp
		logger/SpdLogger.cpp
		communication/RawSocketCommunicator.cpp
		database/InMemoryDatabase.cpp
		client-manager/Client.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/argument-parser
		${CMAKE_CURRENT_SOURCE_DIR}/database
		${CMAKE_CURRENT_SOURCE_DIR}/utils
		${CMAKE_CURRENT_SOURCE_DIR}/client-manager
		${CMAKE_CURRENT_SOURCE_DIR}/communication
		${CMAKE_CURRENT_SOURCE_DIR}/logger)

target_include_directories(libseeder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/argument-parser
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/client-manager
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/utils
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/database
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/communication
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/logger)
