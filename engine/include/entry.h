#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"

#include <stdbool.h>

extern bool create_game(game* out_game);

int main() {

    game game_inst;
    if (!create_game(&game_inst)) {
        FATAL("Could not create game");

        return -1;
    }

    if (!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize) {
        FATAL("The game's function pointers must be defined");
        return -1;
    }
    
    if (!application_create(&game_inst)) {
        FATAL("Application failed to create");
        return -1;
    }

    if (!application_run()) {
        FATAL("Application did not shut down gracefully");
        return -1;
    }

    return 0;
}