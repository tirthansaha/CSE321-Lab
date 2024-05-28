#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#define GDC 3 //constant name value of 3

int main() {
    pid_t pid;
    int i;
    printf("1. Parent process ID: %d\n", getpid()); //prints the process ID of the parent process using getpid()
    pid = fork();
    if (pid == 0) {
        printf("2. Child process ID: %d\n", getpid()); //checks if the current process is the child process

        for (i = 0; GDC > i; i++) {
            if (fork() == 0) {
                printf("%d. Grandchild process ID: %d\n", i + 3, getpid()); //the child process creates 3 grandchild process
                return 0;
            }
        }

        for (i = 0; GDC > i; i++) { //child process waits for grandchild process
            wait(NULL);
        }
        return 0;
    } 
    else {
        wait(NULL); //parent process waits for child process
    }
    return 0;
}