#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

int perfect_num_check(int num){
	
	int sum=0;
	
	for (int i=1; i<=num/2; i++){
		if (num%i==0){
			sum+=i;
		}
	}
	
	return sum;
	
}

void main(){
	
	int start,end;
	
	scanf("%d",&start);
	scanf("%d",&end);

	
	for (int j=start; j<=end; j++){
		if (perfect_num_check(j)==j){
			printf("%d\n",j);
			
		}
	}
	
	
}
	
	

