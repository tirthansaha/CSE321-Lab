#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}
void printArr(int *a, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");
}
int main(int argc, char *argv[]) {
    int n = argc - 1;
    int arr[n];
    int i = 0;

    while (i < n) {
        arr[i] = atoi(argv[i + 1]);
        i++;
    }
    printf("given: ");
    printArr(arr, n);
    qsort(arr, n, sizeof(arr[0]), cmp);
    printf("sorted: ");
    printArr(arr, n);

    return 0;
}