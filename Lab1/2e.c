#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

int Pal(char *str) {
    int strn = strlen(str); //calculates the length of the string
    char *end = str + strn - 1; //calculates the position of the last character by adding the len of the string(strn) to the address of the first character(str) and then subtracting 1
    while (str < end) {
        if (*str != *end) {
            return 0;
        }
        ++str;
        --end;
    }
}
int main(){
    char strArr[MAX];
    printf("Input String:");
    fgets(strArr, MAX, stdin); //taking input and stores in strArr
    strArr[strcspn(strArr, "\n")] = 0; //strcspn function is used to remove the newline character '\n' from the end of the string
    if (Pal(strArr)){
    printf("Palindrome\n");
    }
    else {
    printf("Not Palindrome\n");
    }
    return 0;
}