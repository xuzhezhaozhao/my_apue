#include "apue.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (argc < 2) {
		err_quit("usage: chdir <pathname>");
	}
	int fd;
	char ptr[4096];
	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		err_sys("open error for %s", argv[1]);
	}
	if (fchdir(fd) < 0) {
		err_sys("chdir failed");
	}
	if (getcwd(ptr, 4096) == NULL) {
		err_sys("chdir failed");
	}
	printf("chdir to %s succeeded\n", ptr);
	return 0;
}
