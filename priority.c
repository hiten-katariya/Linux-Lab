#include <stdio.h>

int main() {
    int n, i, j, temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[80], pr[80], wt[80], tat[80];
    wt[0] = 0;

    printf("Enter burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter priorities: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\nP\tBT\tPR\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}
