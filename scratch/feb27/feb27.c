#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    char * mystring = "Hell\0 World";
    // The \0 in the above string is equivalent to
    // char nullchar = '\0';
    int mystringlen = 0;

    mystringlen = strlen(mystring);

    dprintf(STDERR_FILENO, "%d %s \n", mystringlen, mystring);

    //char str2[] = {'H', 'v', 'n'};

    char str2[3];
    str2[0] = 'H';
    str2[1] = 'v';
    str2[2] = 'n';
    str2[3] = '!';

    int mystringlen2 = strlen(str2);
    dprintf(STDOUT_FILENO, "%d %s\n", mystringlen2, str2);

    exit(EXIT_SUCCESS);
}
