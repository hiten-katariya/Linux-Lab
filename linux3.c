#include <stdio.h>

void fcfs(int at[], int bt[], int ct[], int tat[], int wt[], int n, int start) {
    int time = start;
    for (int i = 0; i < n; i++) {
        if (time < at[i]) time = at[i];
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}

int main() {
    int n1, n2;
    printf("Enter number of system processes: ");
    scanf("%d", &n1);
    int at1[n1], bt1[n1], ct1[n1], tat1[n1], wt1[n1];
    printf("Enter arrival and burst time for system processes:\n");
    for (int i = 0; i < n1; i++)
        scanf("%d %d", &at1[i], &bt1[i]);
    printf("Enter number of user processes: ");
    scanf("%d", &n2);
    int at2[n2], bt2[n2], ct2[n2], tat2[n2], wt2[n2];
    printf("Enter arrival and burst time for user processes:\n");
    for (int i = 0; i < n2; i++)
        scanf("%d %d", &at2[i], &bt2[i]);
    fcfs(at1, bt1, ct1, tat1, wt1, n1, 0);
    int end_sys = ct1[n1 - 1];
    fcfs(at2, bt2, ct2, tat2, wt2, n2, end_sys);
    printf("\nSystem Processes:\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n1; i++)
        printf("S%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at1[i], bt1[i], ct1[i], tat1[i], wt1[i]);
    printf("\nUser Processes:\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n2; i++)
        printf("U%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at2[i], bt2[i], ct2[i], tat2[i], wt2[i]);
    return 0;
}
