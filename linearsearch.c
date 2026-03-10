#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int key = 30, i;

    for (i = 0; i < 5; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d", i + 1);
            break;
        }
    }

    if (i == 5)
        printf("Element not found");

    return 0;
}