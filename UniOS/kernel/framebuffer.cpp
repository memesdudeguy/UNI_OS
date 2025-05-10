// kernel/framebuffer.cpp
#include <iostream>

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

char framebuffer[SCREEN_WIDTH * SCREEN_HEIGHT];  // Framebuffer to hold pixel data

// Draw a single pixel at (x, y) position with a given color (represented by a char here)
void draw_pixel(int x, int y, char color) {
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
        framebuffer[y * SCREEN_WIDTH + x] = color;
    }
}

// Draw a string at a specific position on the screen
void draw_string(const char* str, int x, int y) {
    for (int i = 0; str[i] != '\0'; ++i) {
        draw_pixel(x + i, y, str[i]);
    }
}

// Display framebuffer to a simulated terminal (for demonstration)
void display_framebuffer() {
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            std::cout << framebuffer[y * SCREEN_WIDTH + x];
        }
        std::cout << std::endl;
    }
}
