#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

   int fd;
   if ((fd = open(argv[1], O_RDWR)) == -1) printf("���� ���� ����\n");
   else  {
	printf("���� %s ���� ���� : %d\n", argv[1], fd);
	printf("%s", argv[0]);
	}

   close(fd);
   exit(0);
   return 0;
}