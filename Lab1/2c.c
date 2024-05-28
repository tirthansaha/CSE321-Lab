#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 500

void TextMsg(int upF, int lowF, int digF, int charF){ //flags for upper, lower, digit, char
    char err[MAX] = ""; //empty str to store error texts
    if (!upF){
        strcat(err, "Uppercase character missing, ");
        }
    if (!lowF){
        strcat(err, "Lowercase character missing, ");
        }  
    if (!digF){
        strcat(err, "Digit missing, ");
        }
    if (!charF){
        strcat(err, "Special character missing, ");
        }
    if(!upF && !lowF && !digF && !charF){
        err[strlen(err)-2]='\0'; //checks if all character types are missing. removes the trailing comma and space from the err string and prints the error message
        printf("%s ",err);      
    }
    else {
        printf("OK ");
    }
}

void CheckPassword(char *pass){
    int upF,lowF,digF,charF;
    upF= 0;
    lowF= 0;
    digF= 0;
    charF= 0;    
    for (int i=0; pass[i]!='\0'; i++){ //iterates through the string until null terminator
    if (pass[i] == '_' || pass[i] == '$' || pass[i] == '#' || pass[i] == '@'){
            charF= 1;
            }
        if (isupper(pass[i])){
            upF= 1;
            }
        if (islower(pass[i])){
            lowF= 1;
            }
        if (isdigit(pass[i])){
            digF= 1;
            }
    }
    TextMsg(upF,lowF,digF,charF);  
}

int main(){
    char pass[MAX];    
    printf("Input Password:");
    fgets(pass, MAX, stdin);
    CheckPassword(pass);    
    return 0;
}