#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

int main() {
    char mailArr[MAX];
    char *dom="sheba.xyz";
    printf("Input Email:");
    fgets(mailArr, MAX, stdin);
    if(strstr(mailArr,dom)!=NULL){ //strstr func searches a substring 'sheba.xyz'
      printf("Email address is okay\n");
    }
    else{
      printf("Email address is outdated\n");
      }
    return 0;
}