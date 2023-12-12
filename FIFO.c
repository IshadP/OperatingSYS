#include <stdio.h>

void fifo(int n , int pages[], int capac){
    int pages_Q[10];
    int front = 0, rear = 0;
    int pageF = 0;

    for(int i = 0; i < n;i++){
        int currentp = pages[i];
        int pageFd = 0;

        for(int j = front; j < rear; j++){
            if(pages_Q[j] == currentp){
                pageFd = 1;
                break;
            }
        }

        if(!pageFd){
            if(rear < capac){
                pages_Q[rear++] = currentp;
            } else {
                printf("%d", pages_Q[front]);
                pages_Q[front++] = currentp;
            }
            pageF++;
        }
            printf("%d\t", currentp);
        for (int j = front; j < rear; j++) {
            printf("%d ", pages_Q[j]);
        }
        printf("\t\t%d\n", pageF);
    }

    printf("\nTotal Page Faults: %d\n", pageF);
}


void lru(int n, int pages[], int capac) {
    int pages_Q[10];
    int counter[10] = {0};
    int pageF = 0;

    for (int i = 0; i < n; i++) {
        int currentp = pages[i];
        int pageFd = 0;

        for (int j = 0; j < capac; j++) {
            if (pages_Q[j] == currentp) {
                pageFd = 1;
                counter[j] = 1;
                break;
            }
        }

        if (!pageFd) {
            int min = counter[0];
            int index = 0;
            for (int j = 1; j < capac; j++) {
                if (counter[j] < min) {
                    min = counter[j];
                    index = j;
                }
            }
            pages_Q[index] = currentp;  
            counter[index] = 1;        
            pageF++;
        }
        printf("%d\t", currentp);
        for (int j = 0; j < capac; j++) {
            printf("%d %d ", pages_Q[j], counter[j]);
        }
        printf("\t\t%d\n", pageF);
    }

    printf("\nTotal Page Faults: %d\n", pageF);
}


void main(){
    int pages[] = {1, 3, 0, 3, 5, 6, 3, 2, 6, 1, 2, 5, 4, 5, 2, 4};
    int capacity = 3;
    int n = sizeof(pages) / sizeof(pages[0]);

    fifo(n, pages, capacity);
    lru(n, pages, capacity);
    
}