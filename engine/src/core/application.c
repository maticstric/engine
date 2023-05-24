#include "core/application.h"
#include "platform/platform.h"
#include "core/logger.h"
#include "game_types.h"

#include <stdbool.h>

typedef struct application_state {
    game* game_inst;
    bool is_running;
    bool is_suspended;
    platform_state platform;
    short width;
    short height;
    double last_time;
} application_state;

static bool initialized = false;
static application_state app_state;

bool application_create(game* game_inst) {
    if (initialized) {
        ERROR("application_create called more than once");

        return false;
    }

    app_state.game_inst = game_inst;

    // Initialize subsystems
    initalize_logging();

    FATAL("Message: %f", 3.14f);
    ERROR("Message: %f", 3.14f);
    WARN("Message: %f", 3.14f);
    INFO("Message: %f", 3.14f);
    DEBUG("Message: %f", 3.14f);
    TRACE("Message: %f", 3.14f);

    app_state.is_running = true;
    app_state.is_suspended = false;

    if (!platform_startup(&app_state.platform, game_inst->config.name, game_inst->config.start_pos_x, game_inst->config.start_pos_y, game_inst->config.width, game_inst->config.height)) {
        return false;
    }

    if (!app_state.game_inst->initialize(app_state.game_inst)) {
        FATAL("Game failed to initialize");
        return false;
    }

    app_state.game_inst->on_resize(app_state.game_inst, app_state.width, app_state.height);

    initialized = true;

    return true;
}

bool application_run() {
    while (app_state.is_running) {
        if (!platform_pump_messages(&app_state.platform)) {
            app_state.is_running = false;
        }

        if (!app_state.is_suspended) {
            if (!app_state.game_inst->update(app_state.game_inst, (double) 0)) {
                FATAL("Game update failed");
                app_state.is_running = false;

                break;
            }

            if (!app_state.game_inst->render(app_state.game_inst, (double) 0)) {
                FATAL("Game render failed");
                app_state.is_running = false;

                break;
            }
        }
    }

    app_state.is_running = false; // Just in case
    platform_shutdown(&app_state.platform);

    return true;
}