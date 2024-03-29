
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Path: microwave/debug/logger.h
 */

#ifndef __DEBUG_LOGGER_H_
#define __DEBUG_LOGGER_H_

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <cstdarg>

class Logger
{
public:
    static void
    log(const char* context, const char* format, ...) {
        va_list args;
        va_start(args, format);

        std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string timestamp = std::ctime(&now);
        timestamp.pop_back(); // remove trailing newline

        std::cout << "[" << timestamp << "] (" << context << ") ";

        vprintf(format, args);
        std::cout << '\n';

        va_end(args);
    }
};

#endif

/* EOF */

