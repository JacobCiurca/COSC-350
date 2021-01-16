#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int alarm_fired = 0;

	void ding(int sig)
{
	alarm_fired = 1;
}

int main()
{
	pid_t pid;
	printf("alarm application starting\n");

	pid = fork();
	switch(pid){
	case -1:
	perror("fork failed");
	exit(1);
	case(0):
	sleep(5);
	kill(getppid(), SIGALRM);
	exit(0);
}
	printf("waiting for alarm to go off\n");
	struct sigaction s;
	int size = sizeof(s);
	memset(&s, 0, size);
	s.sa_handler = ding;
	sigaction(SIGALRM, &s, 0);
	pause();
	if (alarm_fired)
	printf("Ding!\n");
	printf("done\n");
	exit(0);
}




