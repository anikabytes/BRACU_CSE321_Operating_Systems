#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int n=5,m=4;
int alloc[5][4] = {{0,1,0,3},{2,0,0,0},{3,0,2,0},{2,1,1,5},{0,0,2,2}};
int max[5][4] = {{6,4,3,4},{3,2,2,1},{9,1,2,6},{2,2,2,8},{4,3,3,7}};
int need[5][4];
int avail[4] = {3,3,2,1};
int check[5] = {0,0,0,0,0};

int main(){

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}


	for (int l = 0; l < n; l++) {
		for (int t = 0; t < n; t++) {
			if (check[t] == 0) {

				int count = 0;
				for (int s = 0; s < m; s++) {
					if (need[t][s] > avail[s]){
						count = 1;
						break;
					}
				}

				if (count == 0) {
					for (int y = 0; y < m; y++)
						avail[y] += alloc[t][y];
					check[t] = 1;
				}
			}
		}
	}

	int count = 1;
	
	for(int a=0;a<n;a++){
		if(check[a]==0){
			count=0;
			printf("Deadlock Ahead\n");
			break;
		}
	}
	
	if(count==1){
		printf("Safe state\n");
	}
	
}
