#include <sys/types.h>
#include <sys/wait.h>
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
	if(argc != 3){
	printf("Must have 3 command line arguments\n");
	exit(1);
	}
	pid_t pid;
	pid_t pid1;
	char *message;
	int n;
	int nc, np, tc, tp;
	nc = toInt(argv[1]);
	np = toInt(argv[2]);
	int exit_code;
	printf("fork program starting\n");

	pid = fork();
	switch(pid)
	{
	case -1:
	perror("fork failed");
	exit(2);
	case 0:
	n = 1;
	exit_code = 37;
	break;
	default:
	message = "This is the parent";
	n = np;
	exit_code = 0;
	break;
	}

	
	for(; n > 0; n--){
	if(pid == 0){
	for(int i = 0; i < nc; i++){
	pid1 = fork();
	sleep(1);
	if(pid1 == 0){
	printf("Child pid = %d\n", pid);
	execv("/home/jciurca/child", argv);
}
}
}
else{
	printf("Parent pid = %d\n", pid);
	puts(message);
	sleep(1);
	}
	}
	if (pid != 0){
	int stat_val;
	pid_t child_pid;
	
	child_pid = wait(&stat_val);
	printf("Child has finished: PID = %d\n", child_pid);
	if(WIFEXITED(stat_val)){
	printf("Child has exited with code %d\n", WEXITSTATUS(stat_val));
}
	else{
	printf("Child terminated abnormally\n");
}
	exit(exit_code);
}	
	exit(0);
}
