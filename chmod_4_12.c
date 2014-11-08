#include "apue.h"
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat stat_buf;
	if (stat("foo.o", &stat_buf) < 0) {
		err_sys("stat error for foo.o");
	}
	if (chmod("foo.o", ((stat_buf.st_mode & ~S_IXGRP) | S_ISGID )) < 0) {
		err_sys("chmod error for foo");
	}
	if (chmod("bar.o", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
		err_sys("chmod error for bar");
	}
	return 0;
}
