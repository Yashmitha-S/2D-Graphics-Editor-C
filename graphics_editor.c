#include <stdio.h>

#define WIDTH 40
#define HEIGHT 15

char canvas[HEIGHT][WIDTH];

void clearCanvas() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(int x, int y, int width, int height) {
    for(int i = y; i < y + height && i < HEIGHT; i++) {
        for(int j = x; j < x + width && j < WIDTH; j++) {
            canvas[i][j] = '*';
        }
    }
}
int main() {
    clearCanvas();

    drawRectangle(5, 3, 10, 4);

    displayCanvas();

    return 0;
}