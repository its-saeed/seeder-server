#include "SpdLogger.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/syslog_sink.h>
#include <spdlog/async.h>

namespace logging
{

void init(bool syslog)
{
	static bool init_before = false;

	if (init_before)
		return;

	if (syslog)
		spdlog::syslog_logger_mt<spdlog::async_factory>(LOGGER_NAME);
	else
		spdlog::stdout_color_mt<spdlog::async_factory>(LOGGER_NAME);

	init_before = true;
}

std::shared_ptr<spdlog::logger> log()
{
	return spdlog::get(LOGGER_NAME);
}

void drop()
{
	spdlog::drop(LOGGER_NAME);
}

}
