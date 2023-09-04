#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[]){
	
	
	int arr[argc-1], odd[argc-1], even[argc-1];
	int a;
	int k=0,o=0,e=0,count1=0,count2=0;
	
	for (int i=1; i<argc; i++){
		arr[k] = atoi(argv[i]);
		k++;
	}
	
	
	for (int j=0; j<argc-1 ; j++){
		if (arr[j]%2!=0){
			odd[o] = arr[j];
			o++;
			count1++;
		}
		else if (arr[j]%2==0){
			even[e] = arr[j];
			e++;
			count2++;
		}
	}
	
	printf("The odd numbers are:\n");
	
	for (int l=0; l<count1; l++){
		printf("%d\n",odd[l]);
	}
	
	printf("The even numbers are:\n");
	
	for (int p=0; p<count2; p++){
		printf("%d\n",even[p]);
	}
	
	

}
