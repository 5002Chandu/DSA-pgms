#include <stdio.h>

int main() {
    int arr[5] = {5, 3, 8, 2, 1};
    int i, j, temp;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    return 0;
}