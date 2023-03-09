#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
    int arr[SIZE];
    int i, rand_num;

    srand(1);

    for (i = 0; i < SIZE; i++) {
        rand_num = rand();
        arr[i] = rand_num;
    }

    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}