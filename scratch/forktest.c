#include<stdio.h>
#include<sys/types.h>
#include <stdlib.h>
#include<unistd.h>

static int idata = 111;

int main (int argc, char **argv)
{
    int istack = 222;
    pid_t childPid;

    switch (childPid = fork())
    {
    case -1:
        perror("Fork failed");
        break;
    case 0:
        idata *= 3;
        istack *= 3;
    default:
       sleep(3);
        break;
    }


    pid_t currentPid = getpid();

    printf("PID = (%d)\t childPID = (%d)\t idata = (%d)\t istack = (%d)\n", currentPid, childPid, idata, istack);

    return 0;
}
