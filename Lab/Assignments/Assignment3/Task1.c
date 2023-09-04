#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//SJF Scheduling using preemption

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
	
	int num;
	printf("Please enter the number of processes:");
	scanf("%d",&num);

	
	printf("Enter the process name, arrival time & burst time\n");
	for (int i=0; i<num; i++){
		printf("Process %d: ",i+1);
		scanf("%s %d %d",process[i].name, &process[i].arrival_time, &process[i].burst_time);
		process[i].remaining_time= process[i].burst_time;
	}
	
	int current_time=0, done=0; 
	
	while (done < num){
		
		int check = -1;
		
		for (int j=0; j<num; j++){
			if (process[j].arrival_time <= current_time && process[j].remaining_time > 0){
				if (check == -1 || process[check].remaining_time > process[j].remaining_time){
					check = j;
				}
			}
		}
		
		if (check == -1){
			current_time += 1 ;
		}
		else{
			process[check].remaining_time -= 1;
			current_time+=1;			
			if (process[check].remaining_time == 0){
				process[check].completion_time = current_time;
				process[check].turnaround_time = process[check].completion_time- process[check].arrival_time;
				process[check].waiting_time = process[check].turnaround_time - process[check].burst_time;
				done ++;
			}
		}
	
	
	}
	
	printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
	for (int k = 0; k < num; k++) {
		printf("%s\t%d\t%d\t%d\t%d\t%d\n", process[k].name, process[k].arrival_time, process[k].burst_time, process[k].completion_time, process[k].turnaround_time
		,process[k].waiting_time);
	}
	
	

}
