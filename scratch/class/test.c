#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

	int ret;
	pid_t child;

	int i = 6;
	int j = 9;

	switch((child = fork()))
	{
		case -1:
			perror("fork error");
			return EXIT_FAILURE;
		case 0:
			j = 7;
			printf("Child executing. Child PID: %d. i * j = %d\n", getpid(), i * j);
			exit(i * j);
			break;
		default:
			wait(&ret);
			printf("Child (%d) exit status: %d\n", child, WEXITSTATUS(ret));
			printf("Parent executing. PID: %d. i * j = %d\n", getpid(), i * j);
			break;
	}

	return EXIT_SUCCESS;
}
