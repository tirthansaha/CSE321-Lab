#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

char **makeArgs(int *arr, int size, char *progName) { //int array,size of the array,program name
    char **args = malloc(sizeof(char*) * (size + 2)); //allocates memory for an array of strings(char*) with a size of size+2 //malloc to allocate memory and returns a pointer(args) to the first element of this array,
    args[0] = progName;                                  //extra 2 is for accommodating the program name and a NULL pointer at the end 
                                                        
int i = 0;
    while (i < size) {
        char *buffer = malloc(10); //This buffer will be used to convert each integer in arr to a string
        sprintf(buffer, "%d", arr[i]); //sprintf function to format and write the integer arr[i] into the character buffer buffer as a string
        args[i + 1] = buffer; //string stored in buffer is assigned to the i + 1-th element of the args array,+1 because args[0] is already reserved for the program name
        i++;
    }
    args[size + 1] = NULL; //NULL pointer is assigned to the last element of the args array, a common convention to mark the end of an array of strings
    return args;
}

int main() {
    int data[] = {22, 11, 9, 5, 23};     //declare an array data and its size dataSize. The array contains integers to be processed by child processes
    int dataSize = sizeof(data) / sizeof(data[0]);

    if (fork() == 0) {
        printf("sorting in child process\n");
        char **args = makeArgs(data, dataSize, "./sort");
        if (execv("./sort", args) == -1) {  //execv to replace the current process with the sort program, passing the arguments
            printf("a file not found!\n");
            free(args);
            return -1;
        }
        free(args);
        return 0;

    } else {
        wait(NULL);
        char **args = makeArgs(data, dataSize, "./oddeven");
        printf("OddEven in parent process\n");  //execv to replace the current process with the oddeven program, passing the arguments
        if (execv("./oddeven", args) == -1) {
            printf("a file not found!\n");
            free(args);
            return -1;
        }

        free(args);
        return 0;
    }
}