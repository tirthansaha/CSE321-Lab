#include <stdio.h>
#include <stdlib.h>

int isPerfectNo(int num) {
    int sum = 0;
    for(int a=1; a<num; a++) {
        if (num%a == 0) { //check if the num/a makes reminder 0
            sum += a; //if 0 it adds to sum
        }
    }

    if (sum > 0 && num == sum)
        return 1;
    return 0;
}

int main() {
    int start;
    int end;
    printf("Input Range:\n");
    scanf("%d", &start);
    scanf("%d", &end);
    if (start && end) {
    printf("The Perfect numbers are:\n");
        for (int a=start; a<=end; a++) {
            if (isPerfectNo(a))
                printf("%d\n", a);
            }
        }
    return 0;
}