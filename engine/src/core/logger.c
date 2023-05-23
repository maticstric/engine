#include "core/logger.h"
#include "platform/platform.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

bool initalize_logging() {
    // TODO: Create log file

    return true;
}

void shutdown_logging() {
    // TODO: Clean up logging/write queued entries
}

void log_output(log_level level, const char* message, ...) {
    const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};

    bool is_error = level < LOG_LEVEL_WARN;

    // Imposes a 32,000 character limit on a log entry, which should be plenty
    // We want stack for the speed
    const int msg_length = 32000;

    char out_message[msg_length];
    memset(out_message, 0, sizeof(out_message));

    va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, msg_length, message, arg_ptr);
    va_end(arg_ptr);

    char new_out_message[msg_length];
    sprintf(new_out_message, "%s%s\n", level_strings[level], out_message);

    if (is_error) {
        platform_console_write_error(new_out_message, level);
    } else {
        platform_console_write(new_out_message, level);
    }
}