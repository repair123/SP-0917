#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	pid_t pid;
	if((pid=fork())<0)
		exit(0);
	else if(pid != 0)
		exit(0);
	signal(SIGHUP, SIG_IGN);
	close(0);
	close(1);
	close(2);
	setsid();
	while(1)
	{
		sleep(1);
	}
}

