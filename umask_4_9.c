#include "apue.h" 
#include <fcntl.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char *argv[])
{
	umask(0);
	if (creat("foo.o", RWRWRW) < 0) {
		err_sys("creat error for foo.o");
	}

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (creat("bar.o", RWRWRW) < 0) {
		err_sys("creat error for bar.o");
	}

	return 0;
}
