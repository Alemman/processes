#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

#define MAXLONG 100

void espera(int);


int main(int argc, char *argv[]){
	char string1[MAXLONG], string2[MAXLONG];
	int pos;

	printf("Introduce la cadena 1: ");
	fflush(stdin);
	scanf("%*c%[^\n]",string1);	
	printf("Introduce la cadena 2: ");
	fflush(stdin);
	scanf("%*c%[^\n]",string2);	
	fflush(stdin);

	pid_t pid = fork();

	if(pid < 0){
		printf("Error al crear procesos");
		exit(1);	
	}else if(pid == 0){
		pos = 0;
		while(string2[pos] != '\0'){
			printf("%c",string2[pos]);
			fflush(stdin);
			espera(3);			
			pos +=1;		
		}
		exit(0);
	}

	pos = 0;
	while(string1[pos] != '\0'){
		printf("%c",string1[pos]);
		fflush(stdin);
		espera(4);			
		pos+=1;		
	}
	wait(NULL);	
	exit(0);
}

void espera(int num_times){

	//for(int i = 0; i < num_times; i++){
		sleep(rand()%4);
	//}
}
