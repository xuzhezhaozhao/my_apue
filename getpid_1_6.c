#include "apue.h"

int main(int argc, char *argv[])
{
	printf("Hello world from process ID %d, its parent process ID is %d\n", 
			getpid(), getppid());
	return 0;
}
