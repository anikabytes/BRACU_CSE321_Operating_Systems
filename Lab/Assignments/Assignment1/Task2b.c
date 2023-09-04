#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	FILE *fp;
	
	char store[255];
	fp = fopen("/home/anika-islam/Desktop/cse321/labA1/t2.txt","r");
	fgets(store,255,(FILE*)fp);
	
	char correct[strlen(store)];
	int i=0, j=0;
	
	while (store[i] != '\0'){
		if (!(store[i] == ' ' && store[i+1] == ' ')){
			correct[j] = store[i];
			j++;	
		}
		i ++;
	}
	
	correct[j] = '\0';

	FILE *new_fp;
	new_fp = fopen("/home/anika-islam/Desktop/cse321/labA1/t2_correct.txt","w");
	fputs(correct,new_fp);
	
	fclose(new_fp);
	fclose(fp);
}

