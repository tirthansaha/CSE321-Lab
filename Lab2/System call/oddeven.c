#include <stdlib.h>

int isOdd(int number) {
    if (number % 2 == 0)
        return 0;
    return 1;
}
int main(int argc, char *argv[]) {
    int inputNumber;
    int i = 1;

    while (i < argc) {
        inputNumber = atoi(argv[i]);
        printf("%d > %s\n", inputNumber, isOdd(inputNumber) ? "odd" : "even");
        i++;
    }
    return 0;
}