#include "apue.h" 
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	int in, out;
	off_t cur, hole;
	int cnt, rem;
	int i;
	char buf[BUFSIZE];
	if (argc < 3) {
		err_sys("Usage: copy <filename1> <filename2>\n");
	}

	if ((in = open(argv[1], O_RDONLY)) < 0) {
		err_sys("open %s error", argv[1]);
	}
	if ((out = open(argv[2], O_WRONLY | O_CREAT, S_IREAD | S_IWUSR)) < 0) {
		err_sys("open %s error", argv[2]);
	}

	cur = 0;
	
	while (1) {
		if ((hole = lseek(in, cur, SEEK_HOLE)) < 0) {
			err_sys("lseek error");
		}
		if (lseek(in, cur, SEEK_SET) < 0) {
			err_sys("lseek error");
		}
		if (lseek(out, cur, SEEK_SET) < 0) {
			err_sys("lseek error");
		}
		// write cur to hole - 1
		cnt = (hole - cur) / BUFSIZE;
		rem = (hole - cur) % BUFSIZE;
		printf("hole = %lld\n", (long long)hole);
		printf("cnt = %d, rem = %d\n", cnt, rem);
		for (i = 0; i < cnt; i++) {
			if (read(in, buf, BUFSIZE) == -1) {
				err_sys("read error");
			}
			if (write(out, buf, BUFSIZE) != BUFSIZE) {
				err_sys("write error");
			}
		}
		if (read(in, buf, rem) == -1) {
			err_sys("read error");
		}
		if (write(out, buf, rem) != rem) {
			err_sys("write error");
		}
		
		if ((cur = lseek(in, hole + 1, SEEK_DATA)) < 0) {
			if (ENXIO == errno) {
				break;
			} else {
				err_sys("lseek error");
			}
		}
	}

	return 0;
}
