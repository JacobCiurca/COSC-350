#include <signal.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
	umask(0);
	int foo = open("foo", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	int foo1 = dup(foo);
	char* message = "Hi, Mom";
	int size = sizeof(message);
	pid_t pid = fork();
	if(pid == 0){	
	write(foo, message, size);
	close(foo);
	exit(0);
	}	
	wait(0);
	lseek(foo1, SEEK_SET, 0);
	char buf[size];
	read(foo1, buf, size);
	printf("My son said %s\n", buf);
	close(foo1);
	exit(0);
	}
