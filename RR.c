#include <stdio.h>

int main() {
    int n, i, qt;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[80], rem[80], wt[80], tat[80];
    int t = 0, done;

    printf("Enter burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &qt);

    while (1) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = 0;
                if (rem[i] > qt) {
                    t += qt;
                    rem[i] -= qt;
                } else {
                    t += rem[i];
                    wt[i] = t - bt[i];
                    rem[i] = 0;
                }
            }
        }
        if (done == 1) break;
    }

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\nP\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
