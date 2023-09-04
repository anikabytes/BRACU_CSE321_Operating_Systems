#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char user[100], *first, *last;
	int flag = 0; 
	
	printf("Please enter a word:\n");
	scanf("%s",user);
	
	first = user;
	last = user + strlen(user) - 1;
	
	while (first < last){
		if (*first != *last){
			flag ++;
		}
		first ++;
		last --;
	}
	
	if (flag != 0){
		printf("Not Palindrome\n");
	}
	else{
		printf("Palindrome\n");
	}
		
}
