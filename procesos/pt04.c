#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
	printf("Soy un proceso %d\n", getpid());
	pid_t pid = fork();
	if(pid < 0){
		printf("Error al crear procesos");
		exit(1);	
	}else if(pid == 0){
		printf("Soy proceso hijo : %d\n", getpid());
		exit(0);	
	}
	
	printf("Soy proceso padre : %d \n", getpid());	
	exit(0);
}
