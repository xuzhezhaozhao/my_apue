#include "apue.h"
#undef MAXLINE
#define	MAXLINE 4 
int main(int argc, char *argv[])
{
	char buf[MAXLINE];
	int cnt = 0;
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		++cnt;
		printf("XXX\n");
		if (fputs(buf, stdout) == EOF) {
			err_sys("output error");
		}
	}
	if (ferror(stdin)) {
		err_sys("input error");
	}
	printf("cnt = %d\n", cnt);
	return 0;
}
