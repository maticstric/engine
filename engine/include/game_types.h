#pragma once

#include "core/application.h"

#include <stdbool.h>

typedef struct game {
    application_config config;

    bool (*initialize)(struct game* game_inst);
    bool (*update)(struct game* game_inst, float delta_time);
    bool (*render)(struct game* game_inst, float delta_time);

    void (*on_resize)(struct game* game_inst, unsigned int width, unsigned int height);

    void* state;
} game;