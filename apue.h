#ifndef _APUE_H_
#define _APUE_H

#include <stdarg.h> 	// va_list
#include <sys/types.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>		// exit
#include <string.h>

#define MAXLINE 4096
#define BUFSIZE 4096


void err_quit(const char *fmt, ...);

static void err_doit(int errnoflag, int err, const char *fmt, va_list ap);

void err_quit(const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	err_doit(0, 0, fmt, ap);
	va_end(ap);
	exit(1);
}

void err_sys(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(1);
}

void err_ret(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
}

void err_dump(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	abort();
	exit(1);
}

static void err_doit(int errnoflag, int err, const char *fmt, va_list ap) {
	char buf[MAXLINE];
	vsnprintf(buf, MAXLINE, fmt, ap);
	if (errnoflag) {
		snprintf(buf + strlen(buf), MAXLINE - strlen(buf), ": %s", strerror(err));
	}
	strcat(buf, "\n");
	fflush(stdout);		// in case stdout and stderr are the same
	fputs(buf, stderr);
	fflush(NULL);		// flushes all stdio output streams
}

#endif
