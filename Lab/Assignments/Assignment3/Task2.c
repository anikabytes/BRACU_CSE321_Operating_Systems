#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

// Round Robin 

struct process { char name[4];
	 int arrival_time;
	 int burst_time;
	 int turnaround_time;
	 int waiting_time;
	 int completion_time;
	 int remaining_time;
	};
	
int main(){
	
	struct process process[100];
	
	int num, quantum;
	printf("Please enter the number of processes:");
	scanf("%d",&num);
	
	printf("Enter Time quantum:");
	scanf("%d",&quantum);

	
	printf("Enter the process name & burst time\n");
	for (int i=0; i<num; i++){
		process[i].arrival_time = 0;
		printf("Process %d: ",i+1);
		scanf("%s %d",process[i].name, &process[i].burst_time);
		process[i].remaining_time= process[i].burst_time;
	}
	
	
	int current_time=0, done=0; 
	
	while (done < num){
		
		for (int j=0; j<num; j++){
			if (process[j].arrival_time <= current_time && process[j].remaining_time > 0){
				if (process[j].remaining_time > quantum){
					current_time += quantum;
					process[j].remaining_time -= quantum;
				}
				else{
					current_time += process[j].remaining_time;
					process[j].completion_time = current_time;
					process[j].turnaround_time = process[j].completion_time - process[j].arrival_time;
					process[j].waiting_time = process[j].turnaround_time - process[j].burst_time;
					process[j].remaining_time = 0;
					done++;
				}
			}
		}
	
	
	}
	
	printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
	for (int k = 0; k < num; k++) {
		printf("%s\t%d\t%d\t%d\t%d\t%d\n", process[k].name, process[k].arrival_time, process[k].burst_time, process[k].completion_time, process[k].turnaround_time
		,process[k].waiting_time);
	}

	
}
