#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
	int fd1;
	int fd2;
	
	ssize_t nread1;
	ssize_t nread2;

	long int total1 = 0;
	long int total2 = 0;

	char buffer1[BUFFER_SIZE];
	char buffer2[BUFFER_SIZE];

	if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
		printf("%s: 파일 열기 오류\n", argv[1]);
		perror(argv[1]);
	}

	if ((fd2 = open(argv[2], O_RDONLY)) == -1) {
		printf("%s: 파일 열기 오류\n", argv[2]);
		perror(argv[2]);
		exit(-1);
	}


	while (1) {
		nread1 = read(fd1, buffer1, BUFFER_SIZE);
		nread2 = read(fd2, buffer2, BUFFER_SIZE);


		for(int i = 0; i < BUFFER_SIZE; i++) {

			if(buffer1[i] != buffer2[i]) {
				total1 = total1 + (long int)i;
				printf("%ld byte부터 다름 \n", total1);
				close(fd1);
				close(fd2);
				exit(0);
			}
		}
		
		total1 += nread1;
		total2 += nread2;
	}
}

