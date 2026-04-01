#include <stdio.h> 
int main() { 
    int p[20], bt[20], pri[20], wt[20], tat[20]; 
    int i, j, n, temp; 
    float twt = 0, ttat = 0; 
    // Input: Number of processes 
    printf("Enter the number of processes: "); 
    scanf("%d", &n); 
    // Input: Burst Time and Priority 
    for (i = 0; i < n; i++) { 
        p[i] = i + 1; // Process numbers (1-based index) 
        printf("Enter Burst Time and Priority of Process %d: ", i + 1); 
        scanf("%d %d", &bt[i], &pri[i]); 
    } 
    // Sorting based on priority (Ascending Order, lower value = higher priority) 
    for (i = 0; i < n - 1; i++) { 
        for (j = i + 1; j < n; j++) { 
            if (pri[i] > pri[j]) { // Swap based on priority
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp; 
                temp = bt[i]; 
                bt[i] = bt[j]; 
                bt[j] = temp; 
                temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp; 
            } 
        } 
    } 
    // Waiting Time & Turnaround Time Calculation 
    wt[0] = 0; // First process has zero waiting time 
    tat[0] = bt[0]; 
    ttat = bt[0]; // Initialize turnaround time sum 
    for (i = 1; i < n; i++)  
    { 
        wt[i] = wt[i - 1] + bt[i - 1]; // Waiting time formula 
        tat[i] = wt[i] + bt[i]; // Turnaround time formula 
        twt += wt[i]; // Sum of waiting times 
        ttat += tat[i]; // Sum of turnaround times 
    } 
    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");// Display Output  
    for (i = 0; i < n; i++) { 
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pri[i], bt[i], wt[i], tat[i]); 
    } 
    // Print Average Times 
    printf("\nAverage Waiting Time: %.2f", twt / n); 
    printf("\nAverage Turnaround Time: %.2f\n", ttat / n); 
    return 0;
}