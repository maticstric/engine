#include "platform/platform.h"
#include "core/logger.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <GLFW/glfw3.h>

typedef struct {
    GLFWwindow* glfw_window;
} internal_state;

bool platform_startup(platform_state* plat_state, const char* application_name, int x, int y, int width, int height) {
    plat_state->internal_state = malloc(sizeof(internal_state));

    internal_state* state = (internal_state*)plat_state->internal_state;

    if (!glfwInit()) {
        FATAL("Failed to initialize GLFW");

        return false;
    }

    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // Hide it until shown
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Since we're not using OpenGL

    state->glfw_window = glfwCreateWindow(width, height, application_name, NULL, NULL);

    if (!state->glfw_window) {
        FATAL("Failed to create window");
        glfwTerminate();

        return false;
    }

    glfwSetWindowPos(state->glfw_window, x, y);
    glfwShowWindow(state->glfw_window);

    return true;
}

void platform_shutdown(platform_state* plat_state) {
        internal_state* state = (internal_state*)plat_state->internal_state;

        if (state->glfw_window) {
            glfwDestroyWindow(state->glfw_window);
            state->glfw_window = NULL;
        }

        glfwTerminate();
}

bool platform_pump_messages(platform_state* plat_state) {
    internal_state* state = (internal_state*)plat_state->internal_state;

    glfwPollEvents();

    bool should_continue = !glfwWindowShouldClose(state->glfw_window);

    return should_continue;
}

void* platform_allocate(unsigned long long size, bool aligned) {
    return malloc(size);
}

void platform_free(void* block, bool aligned) {
    free(block);
}

void* platform_zero_memory(void* block, unsigned long long size) {
    return memset(block, 0, size);
}

void* platform_copy_memory(void* dest, const void* src, unsigned long long size) {
    return memcpy(dest, src, size);
}

void* platform_set_memory(void* dest, int value, unsigned long long size) {
    return memset(dest, value, size);
}

void platform_console_write(const char* message, unsigned char color) {
    const char* color_strings[] = {"1;31", "1;31", "1;33", "1;32", "1;34", "1;30"};

    fprintf(stdout, "\033[%sm%s\033[0m", color_strings[color], message);
}

void platform_console_write_error(const char* message, unsigned char color) {
    const char* color_strings[] = {"1;31", "1;31", "1;33", "1;32", "1;34", "1;30"};

    fprintf(stderr, "\033[%sm%s\033[0m", color_strings[color], message);
}

double platform_get_absolute_time() {
    double time = glfwGetTime();
    return time;
}

void platform_sleep(unsigned long long ms) {
    struct timespec ts = {0};
    ts.tv_sec = (long)((double)ms * 0.001);
    ts.tv_nsec = ((long)ms % 1000) * 1000 * 1000;
    nanosleep(&ts, 0);
}