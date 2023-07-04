#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

	char mail[100], outdated[]="kaaj.com", updated[]="sheba.xyz", new[100];

	printf("Please enter email address:\n");
	scanf("%s", mail);
	
	int len=strlen(mail), k=0, ans=0;
	
	for (int i=0; i<len; i++){
		if (mail[i] == '@'){
			for (int j=i+1; j<len;j++){
				if (mail[j] == updated[k]){
					ans ++;
					k ++;
				}
				else if (mail[j] == outdated[k]){
					ans ++;
					k ++;
				}
			}
		}
	}
	
	
	if (ans == strlen(updated)) {
		printf("Email address is okay\n");
	}
	else if (ans == strlen(outdated)) {
		printf("Email address is outdated\n");
		}
	
	
}





