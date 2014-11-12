#include "apue.h" 
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	char buf1[] = "abcdefghij";
	char buf2[] = "ABCDEFGHIJ";
	if ((fd = open("file.hole", O_WRONLY | O_CREAT, S_IRWXU)) < 0) {
		err_sys("creat error");
	}

	if (write(fd, buf1, 10) != 10) {
		err_sys("buf1 write error");
	}

	if (lseek(fd, 65555555, SEEK_SET) == -1) {
		err_sys("lseek error");
	}

	if (write(fd, buf2, 10) != 10) {
		err_sys("buf2 write error");
	}

	return 0;
}
