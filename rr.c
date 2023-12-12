#include <stdio.h>

#define TQ 2

void calcWaitingTime(int a, int bt[a], int at[a]){
    int wt[a], tt[a], rt[a];
    for(int i = 0; i < a; i++){
        rt[i] == bt[i];
    }
        

    wt[0] = 0;
    tt[0] = bt[0];

    int time = 0;
    while(1){
        int done = 1;

        for(int i=0; i < a; i`++){
            if(rt[i] > 0){
                done = 0;
                int et = (rt[i] > TQ) ? TQ : rt[i];

                rt[i] -= et;
                tt[i] = wt[i] + bt[i];
                wt[i] += time;

                time += et;
            }
        }
        if(done) break;
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