#include <stdio.h>
#include <stdbool.h>

#define P 5
#define R 3

void calculateNeed(int need[P][R], int maxm[P][R], int allot[P][R]) {
    printf("The Need Matrix is\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = maxm[i][j] - allot[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int processes[P], int avail[R], int maxm[P][R], int allot[P][R]) {
    int need[P][R];
    calculateNeed(need, maxm, allot);

    bool finish[P];
    int safeSeq[P];
    int work[R];

    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    for (int i = 0; i < P; i++)
        finish[i] = false;

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (finish[p] == false) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += allot[p][k];
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("System is not in a safe state\n");
            return false;
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < P; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");

    return true;
}

int main() {
    int processes[P] = {0, 1, 2, 3, 4};
    int avail[R] = {3, 3, 2};

    int maxm[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int allot[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    isSafe(processes, avail, maxm, allot);

    return 0;
}
