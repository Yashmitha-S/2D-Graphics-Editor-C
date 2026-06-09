#include <stdio.h>
#include <math.h>

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

void drawLine(int x1, int y1, int x2, int y2) {

    if(y1 == y2) {   // Horizontal line
        for(int x = x1; x <= x2 && x < WIDTH; x++) {
            canvas[y1][x] = '*';
        }
    }

    else if(x1 == x2) {   // Vertical line
        for(int y = y1; y <= y2 && y < HEIGHT; y++) {
            canvas[y][x1] = '*';
        }
    }

    else {
        printf("Only horizontal and vertical lines supported currently.\n");
    }
}
void drawTriangle(int x, int y, int height) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j <= i; j++) {
            if(y + i < HEIGHT && x + j < WIDTH) {
                canvas[y + i][x + j] = '*';
            }
        }
    }
}
void drawCircle(int cx, int cy, int radius) {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {

            int dx = x - cx;
            int dy = y - cy;

            int distance = dx * dx + dy * dy;

            if(distance <= radius * radius) {
                canvas[y][x] = '*';
            }
        }
    }
}
void deleteArea(int x, int y, int width, int height) {
    for(int i = y; i < y + height && i < HEIGHT; i++) {
        for(int j = x; j < x + width && j < WIDTH; j++) {
            canvas[i][j] = '_';
        }
    }
}
int main() {
    int choice;

    clearCanvas();

    while(1) {
        printf("\n--- 2D Graphics Editor ---\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete area\n");
        printf("6. Display Canvas\n");
        printf("7. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:
            {
                int x, y, width, height;

                printf("Enter x coordinate: ");
                scanf("%d", &x);

                printf("Enter y coordinate: ");
                scanf("%d", &y);

                printf("Enter width: ");
                scanf("%d", &width);

                printf("Enter height: ");
                scanf("%d", &height);

                drawRectangle(x, y, width, height);

                printf("Rectangle added.\n");
                break;
            }

            case 2:
            {
                int x1, y1, x2, y2;

                printf("Enter x1 y1: ");
                scanf("%d %d", &x1, &y1);

                printf("Enter x2 y2: ");
                scanf("%d %d", &x2, &y2);

                drawLine(x1, y1, x2, y2);

                printf("Line added.\n");
                break;
            }

            case 3:
            {
                int x, y, height;

                printf("Enter x coordinate: ");
                scanf("%d", &x);

                printf("Enter y coordinate: ");
                scanf("%d", &y);

                printf("Enter triangle height: ");
                scanf("%d", &height);

                drawTriangle(x, y, height);

                printf("Triangle added.\n");
                break;
            }
            case 4:
            {
                int cx, cy, radius;

                printf("Enter center x: ");
                scanf("%d", &cx);

                printf("Enter center y: ");
                scanf("%d", &cy);

                printf("Enter radius: ");
                scanf("%d", &radius);

                drawCircle(cx, cy, radius);

                printf("Circle added.\n");
                break;
            }
            case 5:
            {
                int x, y, width, height;

                printf("Enter x coordinate: ");
                scanf("%d", &x);

                printf("Enter y coordinate: ");
                scanf("%d", &y);

                printf("Enter width: ");
                scanf("%d", &width);

                printf("Enter height: ");
                scanf("%d", &height);

                deleteArea(x, y, width, height);

                printf("Area deleted.\n");
                break;
            }

            case 6:
                displayCanvas();
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}