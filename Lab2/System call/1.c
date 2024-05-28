#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_SIZE 300 //max size of the buffer

int main(int argc, char *argv[]) { //argc=argument count argv=argument vector
    int n, fd;
    char buf[MAX_SIZE]; //buf array to store input
    char nl[] = "\n";
    if (2 > argc) { //if command line arg less than 2 then it prints an error message
        printf("give filename\n");
        return -1;
    }
    fd = open(argv[1], O_CREAT | O_WRONLY | O_APPEND, 0644); //opens a file specified by the command-line argument argv[1] O_CREAT (create if not exist), 
    buf[strcspn(buf, "\n")] = 0;                             //O_WRONLY (write-only), O_APPEND (append data to the end of the file)
    n = read(0, buf, MAX_SIZE); //reads input from standard input (file descriptor 0) into the buffer buf then removes the newline character from the buf by replacing it with a null terminator                          
    for (; strcmp(buf, "-1") != 0; n = read(0, buf, MAX_SIZE), buf[strcspn(buf, "\n")] = 0) { //for loop reads input from standard input in a loop until the input is -1
        write(fd, buf, n);
        write(fd, nl, 1);
    }
    close(fd);

    return 0;
}