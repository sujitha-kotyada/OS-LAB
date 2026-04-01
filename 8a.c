#include <stdio.h>

int main() {
    int n, m, i, j, k;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    printf("Enter no. of resource types: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m];
    int available[m];

    printf("\nEnter Allocation matrix: \n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("\nEnter Max Matrix: \n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter Available Resources: \n");
    for(i = 0; i < m; i++)
        scanf("%d", &available[i]);

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    int finish[n], safeSeq[n];
    int work[m];
    for(i = 0; i < m; i++)
        work[i] = available[i];
    for(i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;
    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int flag = 1;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1) {
                    for(k = 0; k < m; k++)
                        work[k] += allocation[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0)
            break;
    }

    if(count == n) {
        printf("\nSystem is in safe state\n");
        printf("Safe Sequence: ");
        for(i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    } else
        printf("\nSystem is NOT in Safe State\n");

    return 0;
}