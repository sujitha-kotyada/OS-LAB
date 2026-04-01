#include <stdio.h> 
#include <stdlib.h> 
int main() { 
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], remaining; 
    float twt = 0, ttat = 0, temp = 0; 
    printf("Enter the number of processes: "); 
    scanf("%d", &n); 
    for (i = 0; i < n; i++) { 
        printf("Enter Burst Time for process %d: ", i + 1); 
        scanf("%d", &bu[i]); 
        ct[i] = bu[i]; // Store original burst time 
    } 
    printf("\nEnter the size of the time slice: "); 
    scanf("%d", &t); 
    remaining = n; // Count of processes yet to complete 
    while (remaining > 0) { 
        for (i = 0; i < n; i++) { 
            if (bu[i] > 0) { 
                if (bu[i] <= t) { 
                    temp += bu[i]; 
                    tat[i] = temp; 
                    bu[i] = 0; 
                    remaining--; 
                 } 
                else { 
                    bu[i] -= t; 
                    temp += t; 
                } 
            } 
        } 
    } 
    for (i = 0; i < n; i++) { 
        wa[i] = tat[i] - ct[i]; 
        ttat += tat[i]; 
        twt += wa[i]; 
    } 
    printf("\nThe Average Turnaround Time is: %.2f", ttat / n); 
    printf("\nThe Average Waiting Time is: %.2f\n", twt / n); 
    printf("\n\tPROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n"); 
    for (i = 0; i < n; i++) { 
        printf("\t%d\t %d\t\t %d\t\t %d\n", i + 1, ct[i], wa[i], tat[i]); 
    } 
    return 0; 
} 