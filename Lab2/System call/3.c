#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int cou=0;
int main(){  
    pid_t a,b,c;
    a=fork();
    cou += 1;
    if(a!=0){
        b=fork();
        cou += 1;
    }
    if(a!=0 && b!=0){
        c=fork();
        cou += 1;
    }
    if(a%2!=0 && a!=0){
        fork();
        cou += 1;
    }  
    if(a!=0 && b%2 && b!=0){
        fork();
        cou += 1;
    }
    if(a!=0 && b!=0 && c!=0 && c%2){
        fork();
        cou += 1;
    }
    if(a!=0 && b!=0 && c!=0){
        printf("\n Number of processes: %d \n",cou);
        return 0;
    }
    return 0;
}