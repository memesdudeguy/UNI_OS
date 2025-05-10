// gui/windowing_system.cpp
#include <iostream>
#include <vector>

struct Window {
    int x, y, width, height;
    char* buffer;

    Window(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {
        buffer = new char[width * height];  // Allocate memory for the window's content
        memset(buffer, ' ', width * height);  // Fill with spaces (empty window)
    }

    void draw() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                // Simulate drawing the window's buffer to the framebuffer
                framebuffer[(y + i) * SCREEN_WIDTH + (x + j)] = buffer[i * width + j];
            }
        }
    }
};

// Framebuffer simulation for drawing
char framebuffer[SCREEN_WIDTH * SCREEN_HEIGHT];
