#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int count=0;
int sum=1;
void *threadfunc(void *arg){
	
	
	int thread_id;
	int k=1;
	
	for (int j=0; j<5; j++){
		
		printf("Thread %d prints %d\n",count,sum);
		sum++;
	}
	count++;
	
	
	
	
}

int main(){
	
	pthread_t thread_arr[5];
	
	for (int i=0; i<5; i++){
		pthread_create(&thread_arr[i],NULL,threadfunc,NULL);
		pthread_join(thread_arr[i],NULL);
	}

}






