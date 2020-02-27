#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUF 32
#define READ_END 0
#define WRITE_END 1

int main(int argc, char** argv)
{
    char writemsg[BUF] = "Boomer Sooner!";
    char readmsg[BUF];
    int fd[2];
    int err;
    pid_t childpid;

    // Create the pipe
    err = pipe(fd);
    if (err == -1)
    {
        perror("Error with pipe");
    }

    switch(childpid = fork())
    {
        case -1:
            perror("There is an error with fork");
            exit(EXIT_FAILURE);
        case 0:
            // we are in the child
            // close the write end
            close(fd[WRITE_END]); //TODO check for errors
            read(fd[READ_END], readmsg, BUF);
            dprintf(STDERR_FILENO, "In the child, we read %s\n", readmsg);
            close(fd[READ_END]);

            break;
        default:
            // we are in the parent
            // close the read end
            close(fd[READ_END]); //TODO check for errors
            write(fd[WRITE_END], writemsg, BUF);
            close(fd[WRITE_END]);
    }

    exit(EXIT_SUCCESS);
}
