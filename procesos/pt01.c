#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	printf("Soy un proceso %d\n", getpid());
	exit(0);
}
