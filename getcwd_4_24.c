#include "apue.h"

int main(int argc, char *argv[])
{
	char ptr[4096];
	if (chdir("/usr/bin/") < 0) {
		err_sys("chdir failed");
	}
	if (getcwd(ptr, 4096) == NULL) {
		err_sys("getcwd failed");
	}
	printf("cwd = %s\n", ptr);
	return 0;
}
