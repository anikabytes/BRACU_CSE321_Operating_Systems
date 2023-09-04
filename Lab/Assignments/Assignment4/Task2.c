#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
/*
This program provides a possible solution using mutex and semaphore.
use 5 Farmers and 5 ShopOwners to demonstrate the solution.
*/
#define MaxCrops 5 // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize]={'R','W','P','S','M'}; //indicating room for different crops
char warehouse[warehouseSize]={'N','N','N','N','N'}; //initially all the room is empty
pthread_mutex_t mutex;
void *Farmer(void *far){
	
	int far_id = *(int *)far;
	
	int i=0; 
	
	char ware; 
	
	
	while (i <= MaxCrops){
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		
		ware = crops[in];
		warehouse[in] = crops[in];
		
		printf("Farmer %d: Inserts Crop %c at %d\n",far_id,ware,i);
		
		in = (in+1)%warehouseSize;
        	i++;
        	
		sem_post(&full);
		pthread_mutex_unlock(&mutex);
	}
	
	printf("Farmer%d: ",far_id);
	for (int j = 0; j < warehouseSize; j++) {
            printf("%c", warehouse[j]);
        }
        printf("\n");
        
        
	
}
	
void *ShopOwner(void *sho)
{
	int shop_id = *(int *)sho;
	
	int i=0; 
	
	char shop;
	
	while (i <= MaxCrops){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		
		shop = crops[out];
		
		printf("Shop owner %d: Removes crops %c from %d\n",shop_id,shop,i);
		
		warehouse[out] = 'N';
		out = (out+1)%warehouseSize;
		i++;
		
		sem_post(&empty);
		pthread_mutex_unlock(&mutex);
	}
	
	printf("ShopOwner%d: ",shop_id);
	for (int j = 0; j < warehouseSize; j++) {
            printf("%c", warehouse[j]);
        }
        printf("\n");
	
}


int main(){

/*initializing thread,mutex,semaphore
*/
	pthread_t Far[5],Sho[5];
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty,0,warehouseSize);//when the warehouse is full thread will wait
	sem_init(&full,0,0);//when the warehouse is empty thread will wait
	int a[5] = {1,2,3,4,5}; //Just used for numbering the Farmer and ShopOwner
	/*create 5 thread for Farmer 5 thread for ShopOwner*/
	pthread_t farmer_id[5], shopowner_id[5];

	for (int i=0; i<5; i++){
		pthread_create(&farmer_id[i],NULL,(void *)Farmer,&a[i]);
	}

	for (int j=0; j<5; j++){
		pthread_create(&shopowner_id[j],NULL,(void *)ShopOwner,&a[j]);
	}

	for (int k=0; k<5; k++){
		pthread_join(farmer_id[k],NULL);
	}

	for (int m=0; m<5; m++){
		pthread_join(shopowner_id[m],NULL);
	}



	// Closing or destroying mutex and semaphore
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);

	return 0;
}
