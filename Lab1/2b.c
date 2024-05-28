#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500 //max size of a string is 500

void SpaceRemover(char *input, char *output){

    FILE *inp= fopen(input, "r");
    FILE *out = fopen(output, "w");
    char str[MAX];
    fgets(str, MAX, inp); //reads strings from inp file
    int a = 0, b = 0;
    while (str[a] != '\0') {           //iterates through str until it gets \0
        while (str[a]==' ' && str[a+1]==' '){ //skips double space
            ++a;
        }
        str[++b] = str[++a]; //removes spaces by incrementing a and copying the character at the updated position to the next position in the array str
    }
    fputs(str, out);
    fclose(inp);
    fclose(out);
}

int main() {
    SpaceRemover("input.txt", "output.txt");
    return 0;
}