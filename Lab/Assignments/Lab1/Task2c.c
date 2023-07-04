# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

int main(){

	char password[100];
	int upper=0, lower=0, digit=0, special=0;
	
	printf("Please enter your new password:\n");
	scanf("%s",password);
	
	
	for (int i=0; i < strlen(password); i++){
		if (isupper(password[i])){
			upper = 1;
		}
		if (islower(password[i])){
			lower = 1;
		}
		if (isdigit(password[i])){
			digit = 1;
		}
		if (password[i] == '_' || password[i] == '$' || password[i] == '#' || password[i] == '@') {
			special = 1;
		}
	}
	
	if (lower != 0 && upper != 0 && digit != 0 && special != 0){
		printf("OK\n");
	}
	else {
		if (lower == 0){
			printf("Lowercase character missing\n");
		}
		if (upper == 0){
			printf("Uppercase character missing\n");
		}
		if (digit == 0){
			printf("Digit missing\n");
		}
		if (special == 0){
			printf("Special character missing\n");
		}
	}
	
		 
}
