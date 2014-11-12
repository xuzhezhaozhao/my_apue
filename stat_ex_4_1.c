#include "apue.h"
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat stat_buf;
	const char *ptr;

	for (i = 1; i < argc; i++) {
		printf("%s: ", argv[i]);
		if (stat(argv[i], &stat_buf) < 0) {
			err_ret("stat error");
			continue;
		}
		if (S_ISREG(stat_buf.st_mode)) {
			ptr = "regular";
		} else if (S_ISDIR(stat_buf.st_mode)) {
			ptr = "directory";
		} else if (S_ISBLK(stat_buf.st_mode)) {
			ptr = "block special";
		} else if (S_ISCHR(stat_buf.st_mode)) {
			ptr = "character special";
		}
		else if (S_ISFIFO(stat_buf.st_mode)) {
			ptr = "fifo";
		} else if (S_ISLNK(stat_buf.st_mode)) {
			ptr = "symbolic link";
		} else if (S_ISSOCK(stat_buf.st_mode)) {
			ptr = "socket";
		} else {
			ptr = "** unknown mode **";
		}
		if (S_ISUID & stat_buf.st_mode) {
			printf("set user id, ");
		}
		if (S_ISGID & stat_buf.st_mode) {
			printf("set group id, ");
		}

		printf("%s\n", ptr);

	}

	return 0;
}
