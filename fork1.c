#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isNum(char c){
	return (c >= '0' && c <= '9')
	? true
	: false;
}
int toInt(char a[]){
	if(*a == '\0'){
	return 0;
	}
	int n;
	n = 0;
	for(int i = 0; a[i] != '\0'; i++){
	if(isNum(a[i]) == false){
	return 0;
}
	n = n * 10 + a[i] - '0';
}
	return n;	
}
int main(int argc, char *argv[])
{
	if(argc != 5){
	printf("Must have 4 command line arguments\n");
	exit(1);
	}
	pid_t pid;
	char *message;
	int n;
	int nc, np, tc, tp;
	int sleeptime;
	nc = toInt(argv[1]);
	np = toInt(argv[2]);
	tc = toInt(argv[3]);
	tp = toInt(argv[4]);
	printf("fork program starting\n");
	pid = fork();
	switch(pid)
	{
	case -1:
	perror("fork failed");
	exit(2);
	case 0:
	message = "This is the child";
	n = nc;
	sleeptime = tc;
	break;
	default:
	message = "This is the parent";
	n = np;
	sleeptime = tp;
	break;
	}
	for(; n > 0; n--){
	puts(message);
	sleep(sleeptime);
	}
	
	exit(0);
}

