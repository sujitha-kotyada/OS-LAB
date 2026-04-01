#include<stdio.h>
int main() 
{ 
    int bt[20], wt[20], tat[20], i, n;
    float ttat, twt; 
    printf("\nEnter the number of processes -- "); 
    scanf("%d", &n); 
    for(i=0;i<n;i++) 
    { 
        printf("\nEnter Burst Time for Process %d -- ", i); 
        scanf("%d", &bt[i]); 
    } 
    wt[0] = twt = 0; 
    tat[0] = ttat = bt[0]; 
    for(i=1;i<n;i++) 
    { 
        wt[i] = wt[i-1] +bt[i-1]; 
        tat[i] = tat[i-1] +bt[i]; 
        twt = twt + wt[i];
        ttat = ttat + tat[i]; 
    } 
    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n"); 
    for(i=0;i<n;i++){
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]); 
    }
    printf("\nAverage Waiting Time -- %f", twt/n); 
    printf("\nAverage Turnaround Time -- %f", ttat/n); 

}