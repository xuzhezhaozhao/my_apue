#include "apue.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
	off_t ls;
	if ((ls = lseek(STDIN_FILENO, 0, SEEK_SET)) == -1) {
		printf("cannot seek\n");
	} else {
		printf("seek OK\n");
	}
	return 0;
}
