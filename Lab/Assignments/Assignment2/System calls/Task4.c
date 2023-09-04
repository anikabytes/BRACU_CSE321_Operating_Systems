#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

	pid_t id;
	int status;
	
	id = fork();
	
	if (id == 0){
		execl("./sort","sort.c",argv[0],argv[1],argv[2],argv[3],argv[4],NULL);
		exit(0);

	}else{
		id = wait(&status);
		execl("./oddeven","oddeven.c",argv[0],argv[1],argv[2],argv[3],argv[4],NULL);
		

	}
		
}
