#include <stdio.h>
#define SIZE 50 
#define MAX 10    

int main() {
    int disk[SIZE] = {0}, start[MAX], length[MAX], status[MAX];
    int i, j, f, k;

    printf("Enter number of files: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        printf("\nFile %d\nStart block: ", i+1);
        scanf("%d", &start[i]);
        printf("Length: ");
        scanf("%d", &length[i]);

        status[i] = 1; 

        if (start[i] < 0 || start[i] + length[i] > SIZE) {
            status[i] = 0; 
        } else {
            for (j = start[i]; j < start[i] + length[i]; j++) {
                if (disk[j] == 1) { 
                    status[i] = 0;
                    break;
                }
            }
        }

        if (status[i]) {
            for (j = start[i]; j < start[i] + length[i]; j++) disk[j] = 1;
        }
    }

    printf("\nAllocation Table:\n");
    printf("File\tStart\tLength\tStatus\n");
    for (i = 0; i < f; i++) {
        printf("%d\t%d\t%d\t%s\n", i+1, start[i], length[i],
               status[i] ? "Allocated" : "Not Allocated");
    }

    return 0;
}
