#include <stdio.h>

int findOpt(int capac, int pages[], int str){
int index = -1;
int far = str;

for (int i = 0; i < capac; i++)
{
    int j;
    for (j = str; j < capac; j++)
    {
        if(pages[i]==pages[j] && j>far ){
            far =j;
            index = i;
        }
    }
    if(j == capac){
        return i;
    }
}
return (index == -1) ? 0 : index;
}

void optimal(int n, int pages[], int capacity) {
    int pageTable[10];
    int pageFaults = 0;

    for (int i = 0; i < 10; i++) {
        pageTable[i] = -1;  // Initialize page entries with -1
    }

    printf("Page\tPage Table\tPage Faults\n");

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int pageFound = 0;

        for (int j = 0; j < capacity; j++) {
            if (pageTable[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            int index = findOpt(capacity, pages, i + 1);
            pageTable[index] = currentPage;
            pageFaults++;
        }

       
        printf("%d\t", currentPage);
        for (int j = 0; j < capacity; j++) {
            printf("%d ", pageTable[j]);
        }
        printf("\t\t%d\n", pageFaults);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

void main(){
int pages[] = {1, 3, 0, 3, 5, 6, 3, 2, 6, 1, 2, 5, 4, 5, 2, 4};
    int capacity = 3;
    int n = sizeof(pages) / sizeof(pages[0]);

    optimal(n, pages, capacity);

}