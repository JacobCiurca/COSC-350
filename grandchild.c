#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	pid_t pid, pid1, ppid;
	int i, endID, status;
	pid = fork();	
	if (pid == 0)
	{
	pid1 = fork();
	if (pid1 > 0)
	{
	for (i = 0; i<100; i++)
	{
	printf("I am your child with ID = %d \n", getpid());
	sleep(1);
	}
	exit(0);
	}
	else{
	ppid = getppid();
	while(1){
	if(getppid() = ppid){
	printf("I am your grandchild with ID = %d \n", getpid());
	sleep(1);
	}
	else{
	exit(0);
}
}
}
}
else{
	while(1){
	endID = waitpid(pid, &status, WNOHANG|WUNTRACED);
	if(endID == 0){
	printf("I am your parent with ID = %d \n", getpid());
	sleep(1);
	}
	else{
	printf("I finish my job \n");
	exit(0);
}
}
}
	return 0;
	}