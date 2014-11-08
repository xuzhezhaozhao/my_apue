#include "apue.h"
#include <fcntl.h>
#include <utime.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int i, fd;
	struct stat stat_buf;
	struct utimbuf time_buf;

	for (i = 1; i < argc; i++) {
		if (stat(argv[i], &stat_buf) < 0) {
			err_ret("%s: stat error", argv[i]);
			continue;
		}
		if ((fd = open(argv[i], O_RDWR | O_TRUNC) < 0)) {
			err_ret("%s: open error", argv[i]);
			continue;
		}
		close(fd);
		time_buf.actime = stat_buf.st_atime;
		time_buf.modtime = stat_buf.st_mtime;
		if (utime(argv[i], &time_buf) < 0) {
			err_ret("%s: utime error", argv[i]);
			continue;
		}
	}

	return 0;
}
