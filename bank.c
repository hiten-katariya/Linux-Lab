
#include <stdio.h>

int main() {
    int n, m, i, j, k;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    printf("Enter no. of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m], need[n][m], f[n], ans[n], ind = 0;

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < n; i++) {
        f[i] = 0;
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j]) { flag = 1; break; }
                if (!flag) {
                    for (j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    ans[ind++] = i;
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 0;
    for (i = 0; i < n; i++)
        if (f[i] == 0) { flag = 1; printf("\nSystem is not in safe state.\n"); break; }

    if (!flag) {
        printf("\nSystem is in safe state.\nSafe sequence: ");
        for (i = 0; i < n - 1; i++)
            printf("P%d -> ", ans[i]);
        printf("P%d\n", ans[n - 1]);
    }
    return 0;
}
