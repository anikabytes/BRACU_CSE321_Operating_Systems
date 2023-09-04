#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {
	
	FILE *file ;
	char *name = argv[1], msg[100];
	
	file = fopen(name, "a+");


	printf("Please enter '-1' to stop writing in the file\n");
	while (1) {
		printf("Enter a string: ");
		fgets(msg,sizeof(msg), stdin);

		if (strcmp(msg, "-1\n") == 0) {
		    break;
		}

		fprintf(file, "%s\n", msg);
	}
	
	fclose(file);
	
	return 0;
}

	
	
