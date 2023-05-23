#pragma once

// Disable assertions by commenting out the below line
#define ASSERTIONS_ENABLED

#ifdef ASSERTIONS_ENABLED
#define debugBreak() __builtin_trap()

void report_assertions_failure(const char* expression, const char* message, const char* file, int line);

#define ASSERT(expr)                                                  \
    {                                                                 \
        if (expr) {                                                   \
        } else {                                                      \
            report_assertions_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                             \
        }                                                             \
    }

#define ASSERT_MSG(expr, message)                                          \
    {                                                                      \
        if (expr) {                                                        \
        } else {                                                           \
            report_assertions_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                  \
        }                                                                  \
    }

#ifdef DEBUG
#define ASSERT_DEBUG(expr)                                            \
    {                                                                 \
        if (expr) {                                                   \
        } else {                                                      \
            report_assertions_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                             \
        }                                                             \
    }
#else
#define ASSERT_DEBUG(expr)
#endif

#else

#define ASSERT(expr)
#define ASSERT_MSG(expr, message)
#define ASSERT_DEBUG(expr)

#endif