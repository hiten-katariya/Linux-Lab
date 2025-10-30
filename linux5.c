#include <stdio.h>

int main() {
    int b[10], p[10], nb, np, i, j, alloc[10], ch;
    printf("Enter no. of blocks: ");
    scanf("%d", &nb);
    printf("Enter block sizes:\n");
    for (i = 0; i < nb; i++) scanf("%d", &b[i]);
    printf("Enter no. of processes: ");
    scanf("%d", &np);
    printf("Enter process sizes:\n");
    for (i = 0; i < np; i++) scanf("%d", &p[i]);

    while (1) {
        printf("\n1.First Fit  2.Best Fit  3.Worst Fit  4.Exit: ");
        scanf("%d", &ch);
        if (ch == 4) break;

        for (i = 0; i < np; i++) alloc[i] = -1;
        int temp[10]; 
        for (i = 0; i < nb; i++) temp[i] = b[i];

        if (ch == 1) {
            for (i = 0; i < np; i++)
                for (j = 0; j < nb; j++)
                    if (temp[j] >= p[i]) { alloc[i] = j; temp[j] -= p[i]; break; }
        }
        else if (ch == 2) {
            for (i = 0; i < np; i++) {
                int best = -1;
                for (j = 0; j < nb; j++)
                    if (temp[j] >= p[i] && (best == -1 || temp[j] < temp[best])) best = j;
                if (best != -1) { alloc[i] = best; temp[best] -= p[i]; }
            }
        }
        else if (ch == 3) {
            for (i = 0; i < np; i++) {
                int worst = -1;
                for (j = 0; j < nb; j++)
                    if (temp[j] >= p[i] && (worst == -1 || temp[j] > temp[worst])) worst = j;
                if (worst != -1) { alloc[i] = worst; temp[worst] -= p[i]; }
            }
        }

        printf("\nProcess\tSize\tBlock");
        for (i = 0; i < np; i++) {
            if (alloc[i] != -1) printf("\nP%d\t%d\tB%d", i + 1, p[i], alloc[i] + 1);
            else printf("\nP%d\t%d\tNot Allocated", i + 1, p[i]);
        }
        printf("\n");
    }
    return 0;
}
