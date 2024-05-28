#include <stdio.h>
int main() {
    int n, p[10], at[10], bt[10], a[10], ct[10], tat[10], wt[10], f[10];
    printf("no. of process: ");
    scanf("%d", &n); 
    printf("\n");
  
    int i=1; //initializes the process IDs and arrival times based on user input.
    while (i<=n) {
        p[i-1]=i;
        int atime;    
        printf("arrival time of P%d: ", i); 
        scanf("%d", &atime);
        at[i-1]=atime; 
        printf("\n");
        i++;
    }   
    int i=1; //initializes the process burst times based on user input
    while (i<=n) {
        p[i-1]=i;
        int btime;    
        printf("burst time of P%d: ", i); 
        scanf("%d", &btime);
        bt[i-1]=btime; 
        printf("\n");
        i++;
    }   
    int j=0; //initializes some arrays and variables to zero, setting up for the calculation of completion time, turnaround time, and waiting time
    while (j<=n) {       
        ct[j]=0;
        tat[j]=0;
        wt[j]=0;
        a[j]=bt[j];
        f[j]=0; 
        j++;
    } 
    int st=0; //represents the current time during the execution of the algorithm
    int t=0; //track of how many processes have been completed
    int check=0; //loop breaker
    while (check>-1) {
        int min=10000; //used to find the process with the minimum burst time
        int c=n; // keep track of the selected process
        if (t==n) {
            break;
        }
        int i=0;
        while (i<n) {
            if ((f[i]==0)&&(at[i]<=st)&&(bt[i]<min)) {
                c=i; //updates the variable c to the current process index i
                min=bt[i]; //updates the minimum burst time to the burst time of the current process i
            }
            i++;
        }
        if (c==n) { //If no process is selected (c is still n)
            st+=1;
        } else {
            bt[c]=bt[c] - 1;
            st=st+1; //reduces its remaining burst time by 1, and increments the current time st by 1
            if (bt[c]==0) {
                ct[c]=st; //if the remaining burst time of the selected process becomes 0, updates the completion time
                f[c]=1;
                t=t+1;
            }
        }
        check++;
    }
    int k=0; //calculates turnaround times and waiting times for each process
    while (k<n) {
        tat[k]=ct[k]-at[k];
        wt[k]=tat[k]-a[k];
        k++;
    }
    int l=0;
    while (l<n) {
        printf("\n");
        printf("Results for P%d-", p[l]);
        printf("\n");
        printf("Completion time: %d", ct[l]);
        printf("\n");
        printf("Waiting time: %d", wt[l]);
        printf("\n");
        printf("Turnaround time: %d", tat[l]);
        printf("\n");
        l++;
    }
    return 0;
}