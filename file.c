#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isNum(char c){
	return (c >= '0' && c <= '9')
	? true
	: false;
}
int main(int argc, char *argv[])
{
	if(argc != 2){
	printf("Must have 1 file as a  command line argument\n");
	exit(1);
	}
	pid_t pid;
	int foo;
	int clone, clone1;
	char a;
	int n = 0;
	
	
	if((foo = open(argv[1], O_RDONLY)) == -1){
	printf("Output File not found\n");
	exit(2);
}
	int size = lseek(foo, 0, SEEK_END);
	lseek(foo, 0, SEEK_SET);
	int exit_code;
	printf("fork program starting\n");
	if ( ( pid = fork()) < 0){
	printf("fork error\n");
	exit(3);
	}
	switch(pid){
	case 0: 
	clone = open("child.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	default:
	clone1 = open("parent.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	}
	for (int i=0; i<size; i++){
	lseek(foo, n, SEEK_SET);
	n++;
	read(foo, &a, 1);
	if(pid == 0){
	if(isNum(a) == true){
	write(clone, &a, 1);
	}
}
	else{
	if(isNum(a) == false){
	write(clone1, &a, 1);
}
}
	}
return 0;
}
	
