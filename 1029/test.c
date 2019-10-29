#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER 512

void main(){
	in i,n,m;
	char c;
	printf("반복할 수 입력 :");
	sacnf("%d",&n);
	for(i=1;i<=n;i++){
		printf("반복할 문자와 반복할 수 입력");
		__fpurge(stdin);
		sacnf(" %c %d",&c,&m);
		for(j=1; j<=m; j++){
			printf("%c",c);
		}
	}
}


