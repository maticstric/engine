#include "core/logger.h"
#include "core/asserts.h"

#include "platform/platform.h"

int main() {
    FATAL("Message: %f", 3.14f);
    ERROR("Message: %f", 3.14f);
    WARN("Message: %f", 3.14f);
    INFO("Message: %f", 3.14f);
    DEBUG("Message: %f", 3.14f);
    TRACE("Message: %f", 3.14f);

    // platform_state state;

    // if (platform_startup(&state, "testbed", 100, 100, 1200, 700)) {
    //     while (true) {

    //     }
    // }

    return 0;
}