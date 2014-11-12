#include "apue.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char *path = "/dev/fd/1";
	int fd;
	if (unlink(path) < 0) {
		err_sys("unlink %s error", path);
	}
	if ((fd = creat(path, S_IREAD)) < 0) {
		err_sys("creat %s error", path);
	}
	return 0;
}
