#include <stdio.h>

int main() {
    int ms, ps, nop, np, rempages, i, j, p[10], f[20], off, pa, pn;
    printf("Enter memory size: ");
    scanf("%d", &ms);
    printf("Enter page size: ");
    scanf("%d", &ps);
    nop = ms / ps;
    printf("Total frames available = %d\n", nop);
    printf("Enter number of processes: ");
    scanf("%d", &np);
    rempages = nop;
    for (i = 0; i < np; i++) {
        printf("Enter number of pages for process %d: ", i + 1);
        scanf("%d", &p[i]);
        if (p[i] > rempages) {
            printf("Memory full! Cannot allocate.\n");
            p[i] = 0;
        } else {
            rempages -= p[i];
            printf("Enter frame numbers for process %d:\n", i + 1);
            for (j = 0; j < p[i]; j++)
                scanf("%d", &f[j]);
            printf("Page Table for P%d:\n", i + 1);
            printf("Page\tFrame\n");
            for (j = 0; j < p[i]; j++)
                printf("%d\t%d\n", j, f[j]);
        }
    }
    printf("\nEnter process number and page number & offset: ");
    scanf("%d %d %d", &i, &pn, &off);
    if (pn < p[i - 1])
        printf("Physical Address = %d\n", f[pn] * ps + off);
    else
        printf("Invalid page number.\n");
    return 0;
}
