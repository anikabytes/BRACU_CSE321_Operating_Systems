#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 10 //producers and consumers can produce and consume upto MAX
#define BUFLEN 6
#define NUMTHREAD 2 /* number of threads */

void * consumer(int *id);
void * producer(int *id);

char buffer[BUFLEN];
char source[BUFLEN]; //from this array producer will store it's production into buffer
int pCount = 0;
int cCount = 0;
int buflen;

//initializing pthread mutex and condition variables
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD] = {0,1};
int i = 0;
int j = 0;

int main() { 
	int i;
	/* define the type to be pthread */
	pthread_t thread[NUMTHREAD];
	char ch[6] = {'a','b','c','d','e','f'};
	strcpy(source,ch);
	//strcpy(source,"abcdef");
	buflen = strlen(source);
	
	pthread_mutex_init(&count_mutex,NULL);
	
	pthread_create(&thread[0],NULL, (void *)producer, &thread_id[0]);
	pthread_create(&thread[1],NULL, (void *)consumer, &thread_id[1]);
	
	pthread_join(thread[0],NULL);
	pthread_join(thread[1],NULL);
	
	pthread_mutex_destroy(&count_mutex);

}

void * producer(int *id){
	
	int thread_id = *(int *)id;
	
	while (pCount < MAX){
		
		pthread_mutex_lock(&count_mutex);
		sleep(1);
		
		while ( j >= BUFLEN)
			pthread_cond_wait(&full,&count_mutex);
		
		buffer[j] = source[j];
		
		
		printf("%d produced %c by Thread %d\n",pCount,buffer[j],thread_id);
		
		j++;
		pCount ++;
		
		pthread_cond_signal(&nonEmpty);
		pthread_mutex_unlock(&count_mutex);
		
		
	}
	
	pthread_exit(NULL);



}

void * consumer(int *id){

	int thread_id = *(int *)id;
	char store;
	
	while (cCount < MAX){
	
		pthread_mutex_lock(&count_mutex);
		sleep(1);
		
		
		while ( j < 0)
			pthread_cond_wait(&nonEmpty,&count_mutex);
		
		
		store = buffer[buflen-j];
				
		printf("%d consumed %c by Thread %d\n",cCount,store,thread_id);
		
		j--;
		cCount ++; 
		
		pthread_cond_signal(&full);
		pthread_mutex_unlock(&count_mutex);
	}
	
	pthread_exit(NULL);
}
