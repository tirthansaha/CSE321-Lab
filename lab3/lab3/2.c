#include <stdio.h>

int main() {
    int n;
    int qt;
    int bt[10];
    int p[10];
    int a[10]; 
    int ct[10];
    int tat[10]; 
    int wt[10];

    printf("Time Quantum: ");
    scanf("%d", &qt); 
    printf("\n");
    printf("No of Process: ");
    scanf("%d", &n); 
    printf("\n");

    int i=1;
    while (i<=n) {
        p[i-1] = i;
        int b;       
        printf("Burst time of P%d: ", i); 
        scanf("%d", &b);
        printf("\n");
        bt[i-1]=b;
        i++;        
    }      

    int j=0; // setting up for the calculation of completion time, turnaround time, and waiting time
    while (j<n) {       
        ct[j],tat[j],wt[j]=0,0,0;
        a[j]=bt[j];
        j++;
    } 
    
    int st=0;
    int check=0;
    while (check>-1) {  //Round Robin scheduling algorithm
        int t=0;
        int i=0;
        while (i<n) {
            int t1=qt;
            if (a[i]==0) {
                t+=1;
                i++;
                continue;
            }
            if (a[i]>qt) {
                a[i]-=qt;
            } else if (a[i]>=0) {
                t1=a[i];
                a[i]=0;
            }
            st=st+t1;
            ct[i]=st;
            tat[i]=st;
            i++;
        }
        if (t==n) {
            break;
        }
        check++;
    }
    int k=0;
    while (k<n) {
        wt[k]=tat[k]-bt[k];
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