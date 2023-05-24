#pragma once

struct game;

#include <stdbool.h>

typedef struct application_config {
    short start_pos_x;
    short start_pos_y;
    short width;
    short height;
    char* name;
} application_config;

bool application_create(struct game* game_inst);

bool application_run();