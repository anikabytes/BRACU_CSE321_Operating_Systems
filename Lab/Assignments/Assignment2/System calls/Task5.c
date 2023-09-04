#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int count=1;
int main(){
	
	pid_t id1, id2, id3, id4;
	
	int status;
	
	
	id1 = fork();
	
	if (id1 == 0){
	
		count++;
		printf("%d.Child process ID:%d\n",count,getpid());
		
		id2 = fork();
		count++;
		
		if (id2 == 0){
			
			printf("%d.Grand Child process ID:%d\n",count,getpid());
			exit(0);
		}
		
		id3 = fork();
		count++;
		
		if (id3 == 0){
			
			printf("%d.Grand Child process ID:%d\n",count,getpid());
			exit(0);
		}
		
		id4 = fork();
		count++;
		
		if (id4 == 0){
			
			printf("%d.Grand Child process ID:%d\n",count,getpid());
			exit(0);
		}
		
		
	}
	else{
		printf("%d.Parent process ID:%d\n",count,getpid());
		wait(&status);
	}
	

}
	
