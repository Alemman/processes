#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

void espera(char *);
int i = 0;

int main(int argc, char *argv[]){
	printf("Soy un proceso (antes de fork()) : %d\n", getpid());
	pid_t pid = fork();
	if(pid < 0){
		printf("Error al crear procesos");
		exit(1);	
	}else if(pid == 0){
		printf("Soy proceso hijo : %d\n", getpid());
		espera("HIJO");
		printf("Proceso hijo terminado.\n");
		exit(0);	
	}
	printf("Proceso padre en espera que hijo termine ....\n");
	espera("PADRE");	
	wait(NULL);
	printf("Soy proceso padre : %d \n", getpid());	
	exit(0);
}

void espera(char *nombre){
	const int NUM_TIMES = 5;
	for(int i = 0; i < NUM_TIMES; i++){
		sleep(rand()%4);
		printf("Ciclo %d esta listo ...(%s)\n", i, nombre);
	}
}
