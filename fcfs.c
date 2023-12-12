#include <stdio.h>

void calcWaitingTime(int i, int bt[i], int at[i]){
    int wt[i],tt[i];

    wt[0]=0;
    tt[0] = bt[0];
    for(int j = 1; j < i; j++){
        wt[j] = bt[j-1] + wt[j-1];
        printf("The waiting time for process %d is %d\n", j+1, wt[j]);
        tt[j] = wt[j] + bt[j];
        printf("The turnaround time for process %d is %d\n", j+1, tt[j]);
    }
}

void main(){
    int i;
    printf("Enter the number of processes: ");
    scanf("%d", &i);
    int bt[i], at[i];

    for(int j = 0; j < i; j++){
        printf("Enter the arrival time for Process %d: ", j+1);
        scanf("%d", &at[j]);
        printf("Enter the burst time for Process %d: ", j+1);
        scanf("%d", &bt[j]);
    }

    calcWaitingTime(i, bt, at);

}