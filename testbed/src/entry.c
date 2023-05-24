#include "entry.h"
#include "game.h"
#include "platform/platform.h"

#include <stdbool.h>

bool create_game(game* out_game) {
    out_game->config.start_pos_x = 100;
    out_game->config.start_pos_y = 100;
    out_game->config.width = 1200;
    out_game->config.height = 700;
    out_game->config.name = "testbed";

    out_game->update = game_update;
    out_game->render = game_render;
    out_game->initialize = game_initialize;
    out_game->on_resize = game_on_resize;

    out_game->state = platform_allocate(sizeof(game_state), false);

    return true;
}