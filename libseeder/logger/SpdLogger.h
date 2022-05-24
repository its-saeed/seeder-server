#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <array>

#include <spdlog/logger.h>

namespace logging
{

static constexpr const char* LOGGER_NAME = "seeder";

void init();
void drop();

std::shared_ptr<spdlog::logger> log();

}

#endif // LOGGER_H
