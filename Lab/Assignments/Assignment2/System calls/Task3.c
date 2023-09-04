#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int count=0,sum=0;
int process_create(){
	
	pid_t id;
	
	id = fork();
	count++;
	
	int status;
	
	if (id==0){
		if (getpid()%2!=0){
			process_create();
			count++;
		}
		
	}
	else{
		id = wait(&status);
		exit(0);
	}
	
	return count;
}

int main(){
	
	int a,b,c;
	a =  process_create();
	b = process_create();
	c = process_create();
	
	sum = sum+a+b+c;
	
	printf("%d\n",sum);
}

		
	
	
	
	
	
	
	
	
	
	

