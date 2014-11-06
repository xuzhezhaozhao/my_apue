#include "apue.h"

#define MAXSIZE 1024

int main(int argc, char *argv[])
{
	if (argc < 3) {
		err_quit("usage dup2 old new");
	}
	int old = atoi(argv[1]), new = atoi(argv[2]);
	int fd;
	int temp[MAXSIZE];
	int cnt = 0;
	int i;

	close(new);
	if (EBADF != errno) {	// EBADF means invalid open file descriptor error
		err_sys("close error");
	}

	while ((fd = dup(old)) != -1 && fd < new) {
		temp[cnt++] = fd;
	}
	if (-1 == fd) {
		err_sys("dup error");
	}

	for (i = 0; i < cnt; i++) {
		if (close(temp[i]) == -1) {
			err_sys("close error");
		}
	}

	if (fd == new) {
		printf("dup2 OK\n");
	}

	return 0;
}
