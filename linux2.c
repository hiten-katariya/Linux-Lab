#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 100, f[100] = {0}, ch, st, len, i, j, ind[50];

    while (1) {
        printf("\n1. Sequential  2. Indexed  3. Linked  4. Exit: ");
        scanf("%d", &ch);
        if (ch == 4) break;

        switch (ch) {
            case 1:
                printf("Enter start block & length: ");
                scanf("%d %d", &st, &len);
                for (i = st; i < st + len; i++)
                    if (f[i]) { printf("Block not free\n"); break; }
                if (i == st + len) {
                    for (i = st; i < st + len; i++) f[i] = 1;
                    printf("File allocated (Sequential)\n");
                }
                break;

            case 2:
                printf("Enter index block: ");
                scanf("%d", &st);
                if (f[st]) { printf("Block already used\n"); break; }
                f[st] = 1;
                printf("Enter number of blocks: ");
                scanf("%d", &len);
                for (i = 0; i < len; i++) {
                    scanf("%d", &ind[i]);
                    if (f[ind[i]]) { printf("Block already used\n"); break; }
                }
                if (i == len) {
                    for (i = 0; i < len; i++) f[ind[i]] = 1;
                    printf("File allocated (Indexed)\n");
                }
                break;

            case 3:
                printf("Enter start & length: ");
                scanf("%d %d", &st, &len);
                for (i = 0; i < len; i++) {
                    printf("Enter block %d: ", i + 1);
                    scanf("%d", &j);
                    if (f[j]) { printf("Block already used\n"); break; }
                    f[j] = 1;
                }
                if (i == len) printf("File allocated (Linked)\n");
                break;
        }
    }
    return 0;
}
