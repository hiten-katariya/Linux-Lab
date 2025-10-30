#include <stdio.h>
#include <stdlib.h>

int main() {
    int rq[20], n, i, j, head, move, temp, sum = 0, ch;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request sequence: ");
    for (i = 0; i < n; i++) scanf("%d", &rq[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);

    while (1) {
        printf("\n1.FCFS  2.SCAN  3.C-SCAN  4.Exit: ");
        scanf("%d", &ch);
        if (ch == 4) break;

        sum = 0;
        int seq[20];
        for (i = 0; i < n; i++) seq[i] = rq[i];

        if (ch == 1) {
            int curr = head;
            for (i = 0; i < n; i++) {
                sum += abs(seq[i] - curr);
                curr = seq[i];
            }
            printf("Total head movement = %d\n", sum);
        }

        else if (ch == 2) {
            printf("Enter total disk size: ");
            int size; scanf("%d", &size);
            printf("Enter head movement (1->High, 0->Low): ");
            scanf("%d", &move);

            seq[n++] = head;
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (seq[i] > seq[j]) { temp = seq[i]; seq[i] = seq[j]; seq[j] = temp; }

            int pos;
            for (i = 0; i < n; i++) if (head == seq[i]) { pos = i; break; }

            if (move == 1) {
                for (i = pos; i < n; i++) sum += abs(seq[i + 1] - seq[i]);
                sum += abs((size - 1) - seq[n - 1]);
                sum += seq[pos - 1];
            } else {
                for (i = pos; i > 0; i--) sum += abs(seq[i] - seq[i - 1]);
                sum += seq[0];
                sum += abs((size - 1) - seq[pos + 1]);
            }
            printf("Total head movement = %d\n", sum);
        }

        else if (ch == 3) {
            printf("Enter total disk size: ");
            int size; scanf("%d", &size);
            printf("Enter head movement (1->High, 0->Low): ");
            scanf("%d", &move);

            seq[n++] = head;
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    if (seq[i] > seq[j]) { temp = seq[i]; seq[i] = seq[j]; seq[j] = temp; }

            int pos;
            for (i = 0; i < n; i++) if (head == seq[i]) { pos = i; break; }

            if (move == 1) {
                for (i = pos; i < n - 1; i++) sum += abs(seq[i + 1] - seq[i]);
                sum += abs((size - 1) - seq[n - 1]);
                sum += (size - 1);
                for (i = 0; i < pos; i++) sum += abs(seq[i + 1] - seq[i]);
            } else {
                for (i = pos; i > 0; i--) sum += abs(seq[i] - seq[i - 1]);
                sum += seq[0];
                sum += (size - 1);
                for (i = n - 1; i > pos; i--) sum += abs(seq[i] - seq[i - 1]);
            }
            printf("Total head movement = %d\n", sum);
        }
    }
    return 0;
}
