#include <signal.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
void sig_usr(int sig)
{	
	if(sig == SIGUSR1){
	printf("Hi Honey! Anything wrong?\n");
	}
	if(sig == SIGUSR2){
	printf("Do you make trouble again?\n");
	}
}

int main()
{
	struct sigaction s;
	s.sa_handler = sig_usr;
	pid_t pid;
	pid_t pid1;
	printf("SIGUSR program starting.\n");
	pid = fork();
	if(pid == 0){
	sleep(1);
	kill(getppid(), SIGUSR1);
	exit(0);
}
	else{
	pid1 = fork();
	if(pid1 == 0){
	sleep(2);
	kill(getppid(), SIGUSR2);
	exit(0);
}
	else{
	sigaction(SIGUSR1, &s, 0);
	pause();
	sigaction(SIGUSR2, &s, 0);
	pause();
}
}
	exit(0);
}

