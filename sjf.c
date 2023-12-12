#include <stdio.h>

void calcWaitingTime(int a, int bt[a], int at[a]){
    int wt[a], tt[a];

    for(int i = 1; i < a; i++){
        for(int j = i+1; j < a; j++){
            if(at[i] < at[j]){
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }

    wt[0] = 0;
    tt[0] = bt[0];
    for (int i = 1; i < a; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
        tt[i] = wt[i] + bt[i];
        printf("%d %d", wt[i], tt[i]);
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