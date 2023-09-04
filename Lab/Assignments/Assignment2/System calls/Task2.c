#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	
	pid_t id1,id2;
	
	int status;
	
	id1 = fork();
	
	if (id1 == 0){
		id2 = fork();
		if (id2 == 0){
			printf("I am grandchild\n");
		}
		else{
			id2 = wait(&status);
			printf("I am child\n");
		}
	}
	else{
		id1 = wait(&status);
		printf("I am parent\n");
	}
	

}
