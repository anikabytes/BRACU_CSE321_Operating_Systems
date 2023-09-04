#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int count=1;
int *ans; 

int add_ascii(char *name){
	
	int sum=0,i=0;
	
	while (name[i] != '\0'){
		sum = sum + name[i];
		i++;
	}
	
	return sum;
	
}

void *threadfunc(void *arg){
	
	char name[100];
	int add;
	//int *ans = (int*)arg;
	int thread_id[3];
	
	for (int j=0; j<1; j++){
		printf("%d.Please enter your name:\n",count);
		scanf("%s",name);
		add = add_ascii(name);
		//*ans = add;
		}
		
	count++;
	pthread_exit(add);
	
}


int main(){
	
	pthread_t thread_arr[3];
	int check[3];
	int j=0;
	
	for (int i=0; i<3; i++){
		pthread_create(&thread_arr[i],NULL,threadfunc,NULL);
		pthread_join(thread_arr[i],&ans);
		check[j] = ans;
		j++;
	}
	
	//printf("%d %d %d\n",check[0],check[1],check[2]);
	
	if (check[0] == check[1] && check[0] == check[2] && check[1] == check[2]){
		printf("Youreka\n");
	}
	else if (check[0] == check[1] || check[0] == check[2] || check[1] == check[2]){
		printf("Miracle\n");
	}
	else{
		printf("Hasta la vista\n");
	}
	
}




		

