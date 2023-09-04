#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int count=0;
void *threadfunc(void *arg){
	
	count++;
	printf("thread-%d running\n",count);
	int thread_id;
	
	for (int j=0; j<5; j++){
		sleep(0.002);
	}
	printf("thread-%d closed\n",count);	
	
}

int main(){
	
	pthread_t thread_arr[5];
	
	for (int i=0; i<5; i++){
		pthread_create(&thread_arr[i],NULL,threadfunc,NULL);
		pthread_join(thread_arr[i],NULL);
	}

}

