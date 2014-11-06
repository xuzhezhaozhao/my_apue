#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);

int main(int argc, char *argv[])
{
	char buf[MAXLINE];
	char arg[MAXLINE];
	pid_t pid;
	int status;
	char *find;

	if (signal(SIGINT, sig_int) == SIG_ERR) {
		err_sys("signal error");
	}

	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if ('\n' == buf[strlen(buf) - 1]) {
			buf[strlen(buf) - 1] = '\0';
		}
		if ((pid = fork()) < 0) {
			err_sys("fork error");
		} else if (pid == 0) {
			/* child */
			arg[0] = '\0';
			find = strchr(buf, ' ');
			if (find) {
				*find = '\0';
				strcpy(arg, find + 1);
			}
			
			if (arg[0]) {
				execlp(buf, buf, arg, (char *)0);
			} else {
				execlp(buf, buf, (char *)0);
			}

			err_ret("couldn't execute: %s", buf);
			exit(127);
		}

		/* parent */
		if ((pid = waitpid(pid, &status, 0)) < 0) {
			err_sys("waitpid error");
		}
		printf("%% ");
	}
	return 0;
}

void sig_int(int signo) {
	printf("interrupt\n%% ");
}
