#include <stdio.h>
#include <math.h>
#include "minilibx-linux/mlx.h"
#include "header/cub.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    void* mlx_ptr;
    void* win_ptr;
} Window;

float angle = 0.0;

void drawLine(Window* window, Point start, Point end) {
    float dx = end.x - start.x;
    float dy = end.y - start.y;
    float steps = fmaxf(fabsf(dx), fabsf(dy));

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = start.x;
    float y = start.y;

    for (int i = 0; i <= steps; i++) {
        mlx_pixel_put(window->mlx_ptr, window->win_ptr, roundf(x), roundf(y), 0xFFFFFF);
        x += xIncrement;
        y += yIncrement;
    }
}

void rotateLine(Window* window, Point origin, float length) {

    Point end;
    end.x = origin.x + length * cos(angle);
    end.y = origin.y + length * sin(angle);

    mlx_pixel_put(window->mlx_ptr, window->win_ptr, origin.x, origin.y, 0xFFFFFF);
    mlx_pixel_put(window->mlx_ptr, window->win_ptr, end.x, end.y, 0xFFFFFF);
    drawLine(window, origin, end);
}

int handleKeyPress(int keycode, Window* window, Point origin) {
    if (keycode == KEY_Q) { // 'Q' key
        angle -= 0.1;
        rotateLine(window, origin, 200);
    } else if (keycode == KEY_E) { // 'E' key
        angle += 0.1;
        rotateLine(window, origin, 200);
    }
    return 0;
}

int main() {
    Window window;
    window.mlx_ptr = mlx_init();
    window.win_ptr = mlx_new_window(window.mlx_ptr, WIDTH, HEIGHT, "Rotating Line");

    Point origin = { WIDTH / 2, HEIGHT / 2 }; // Fixed point of rotation
    float length = 200.0; // Length of the line segment

    mlx_hook(window.win_ptr, 2, 1L << 0, &handleKeyPress, &window); // Register key press event handler

    // rotateLine(&window, origin, length);

    mlx_loop(window.mlx_ptr);

    return 0;
}
