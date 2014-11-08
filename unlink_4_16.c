#include "apue.h" 
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char buf[4096];
	int fd;
	if ((fd = open("tempfile.o", O_RDWR)) < 0) {
		err_sys("open error");
	}
	if (unlink("tempfile.o") < 0) {
		err_sys("unlink error");
	}
	printf("file unlinked\n");
	if (read(fd, buf, 4096) < 0) {
		err_sys("read error");
	}
	printf("read ok\n");
	sleep(15);
	printf("done\n");
	return 0;
}
