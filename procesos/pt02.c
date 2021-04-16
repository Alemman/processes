#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
	printf("Soy un proceso (Antes de fork): %d\n", getpid());
	pid_t pid = fork();
	printf("fork() regresa : %d\n", (int)pid);
	printf("Soy un proceso : %d\n", getpid());	
	
	exit(0);
}
