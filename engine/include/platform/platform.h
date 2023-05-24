#pragma once

#include <stdbool.h>

typedef struct platform_state {
    void* internal_state;
} platform_state;

bool platform_startup(platform_state* plat_state, const char* application_name, int x, int y, int width, int height);
void platform_shutdown(platform_state* plat_state);

bool platform_pump_messages(platform_state* plat_state);

void* platform_allocate(unsigned long long size, bool aligned);
void platform_free(void* block, bool aligned);
void* platform_zero_memory(void* block, unsigned long long size);
void* platform_copy_memory(void* dest, const void* src, unsigned long long size);
void* platform_set_memory(void* dest, int value, unsigned long long size);

void platform_console_write(const char* message, unsigned char color);
void platform_console_write_error(const char* message, unsigned char color);

double platform_get_absolute_time();

void platform_sleep(unsigned long long ms);