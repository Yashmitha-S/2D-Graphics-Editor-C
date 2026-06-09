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
    int choice;

    clearCanvas();

    while(1) {
        printf("\n--- 2D Graphics Editor ---\n");
        printf("1. Draw Rectangle\n");
        printf("2. Display Canvas\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                drawRectangle(5, 3, 10, 4);
                printf("Rectangle added.\n");
                break;

            case 2:
                displayCanvas();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}