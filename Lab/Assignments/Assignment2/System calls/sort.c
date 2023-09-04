#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[]){
	
	printf("The given array is sorted in descending order:\n");
	
	int arr[argc-1];
	int a;
	int k=0,count=0;
	
	for (int i=1; i<argc; i++){
		arr[k] = atoi(argv[i]);
		k++;
		count++;
	}
	
	
	for (int j=0; j<count ; j++){
		for (int m=0; m<count-j-1; m++){
			if (arr[m] < arr[m+1]){
				a = arr[m];
				arr[m] = arr[m+1];
				arr[m+1] = a;
			}
		}
	}
	
	for (int n=0; n<count; n++){
		printf("%d\n",arr[n]);
	}

}
