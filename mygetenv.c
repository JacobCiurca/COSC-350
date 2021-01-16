#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
extern char **environ;
void mygetenv(char *arg){
	char **p = environ;
	char c[50];
	while(*p != NULL){
	char *l = strchr(*p, '=');
	sprintf(c, "%.*s", l - *p, *p);
	if(strcmp(c, arg) == 0){
	printf("%s\n", strchr(*p, '=')+1);}
	*p++;
	}
}


int main(int argc, char *argv[], char *envp[]){
	if(argc != 2){
	printf("Please enter the name of 1 environment variable as a command line argument\n");
	exit(1);
}
	mygetenv(argv[1]);
	exit(0);
}

