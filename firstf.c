#include <stdio.h>

void firstFit(int a, int b, int blk[], int pro[]){
    int flag[a], alloc[a];

    for(int i = 0; i < a; i++){
        flag[i] = 0;
        alloc[i] = -1;
    }

    for(int i = 0; i < b; i++){
        for(int j = 0; j < a; j++){
            if(blk[j] >= pro[i] && flag[i] == 0){
                flag[i] = 1;
                alloc[i] = j;
            }
        }
    }
    printf("Process\tBlock\n");
    for (int i = 0; i < b; i++) {
        if (alloc[i] != -1) {
            printf("%d\t%d\n", i + 1, alloc[i] + 1);
        } else {
            printf("%d\tNot Allocated\n", i + 1);
        }
    }

}

void bestFit(int a, int b, int blk[], int pro[]){
    int flag[a], alloc[a];

    for(int i = 0; i < a; i++){
        flag[i] = 0;
        alloc[i] = -1;
    }

    for(int i = 0; i < b; i++){
        int bestIndex = -1;
        for(int j = 0; j < a; j++){
            if(blk[j] >= pro[i] && flag[i] == 0){
                if(bestIndex == -1 || blk[j] < blk[bestIndex]){
                    bestIndex = j;
                }
                }
                }
                if(bestIndex != -1){
                flag[i] = 1;
                alloc[i] = bestIndex;
                
            }
        }
    
    printf("Process\tBlock\n");
    for (int i = 0; i < b; i++) {
        if (alloc[i] != -1) {
            printf("%d\t%d\n", i + 1, alloc[i] + 1);
        } else {
            printf("%d\tNot Allocated\n", i + 1);
        }
    }

}

void bestFit(int a, int b, int blk[], int pro[]){
    int flag[a], alloc[a];

    for(int i = 0; i < a; i++){
        flag[i] = 0;
        alloc[i] = -1;
    }

    for(int i = 0; i < b; i++){
        int wIndex = -1;
        for(int j = 0; j < a; j++){
            if(blk[j] >= pro[i] && flag[i] == 0){
                if(wIndex == -1 || blk[j] > blk[wIndex]){
                    wIndex = j;
                }
                }
                }
                if(wIndex != -1){
                flag[i] = 1;
                alloc[i] = wIndex;
                
            }
        }
    
    printf("Process\tBlock\n");
    for (int i = 0; i < b; i++) {
        if (alloc[i] != -1) {
            printf("%d\t%d\n", i + 1, alloc[i] + 1);
        } else {
            printf("%d\tNot Allocated\n", i + 1);
        }
    }

}

void main(){
    int a,b;
    printf("Enter block number: ");
    scanf("%d", &a);
    printf("Enter process number: ");
    scanf("%d", &b);

    int blk[a], pro[b];

    for(int i = 0; i < a; i++){
        printf("Enter block %d size: ", i+1);
        scanf("%d", &blk[i]);
    }

    for(int i = 0; i < b; i++){
        printf("Enter process %d size: ", i+1);
        scanf("%d", &pro[i]);
    }

    firstFit(a,b,blk,pro);
    bestFit(a,b,blk,pro);
    worstFit(a,b,blk,pro);
}