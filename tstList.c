#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

int main() {
    int numPoints = 5;
    struct Point* points = malloc(numPoints * sizeof(struct Point));

    if (points == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get the address of the struct array
    struct Point* address = &points[1];
    points[1].x = 9;
    points[2].y = 7;

    // Print the address
    printf("Address of the struct array: %p\n", address);

    address = &points[2];

    printf("sum of them is [%d]\n",points[1].x+address->y);
    // Print the address
    printf("Address of the struct array: %p\n", address);

    free(points); // Free the dynamically allocated memory

    return 0;
}