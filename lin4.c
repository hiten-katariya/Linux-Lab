#include <stdio.h>

int main() {
    int ms, bs, nob, ef, n, mp[10], tif = 0, p = 0, ch;
    while (1) {
        printf("\n1. MFT  2. MVT  3. Exit: ");
        scanf("%d", &ch);
        if (ch == 3) break;

        if (ch == 1) {
            printf("Enter total memory size: ");
            scanf("%d", &ms);
            printf("Enter block size: ");
            scanf("%d", &bs);
            nob = ms / bs;
            ef = ms - nob * bs;
            printf("Enter number of processes: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter memory for process %d: ", i + 1);
                scanf("%d", &mp[i]);
            }
            printf("\nNo. of Blocks = %d", nob);
            for (int i = 0; i < n && i < nob; i++) {
                if (mp[i] > bs)
                    printf("\nProcess %d: Not allocated (too large)", i + 1);
                else {
                    printf("\nProcess %d: Allocated", i + 1);
                    tif += bs - mp[i];
                }
            }
            printf("\nTotal Internal Fragmentation = %d", tif);
            printf("\nExternal Fragmentation = %d\n", ef);
        }

        else if (ch == 2) {
            printf("Enter total memory size: ");
            scanf("%d", &ms);
            int temp = ms, pno = 1;
            while (1) {
                printf("Enter memory required for process %d (0 to stop): ", pno);
                scanf("%d", &bs);
                if (bs == 0) break;
                if (bs <= temp) {
                    printf("Process %d allocated.\n", pno++);
                    temp -= bs;
                } else {
                    printf("Memory Full! Remaining = %d\n", temp);
                    break;
                }
            }
            printf("Total memory left (External Fragmentation) = %d\n", temp);
        }
    }
    return 0;
}
