#include <stdio.h>
#include <stdlib.h>
float summation(float p, float q) {
    return p+q;
}
float subtract(float p, float q) {
    return p-q;
}
float multi(float p, float q) {
    return p*q;
}

int main() {
    float p,q;
    printf("First no:");
    scanf("%f", &p);
    printf("Second no:");
    scanf("%f", &q);
    if (p==q){
        printf("Multiplication:%f \n", multi(p,q));
    }
    if (p>q){
        printf("Subtraction:%f \n", subtract(p,q));
    }
    if (p<q){
        printf("Summation:%f \n", summation(p,q));
    }
   return 0; 
}