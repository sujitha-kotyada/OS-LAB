#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k = 0, page_faults = 0;
    int found;

    printf("Enter number of Pages: ");
    scanf("%d", &n);

    printf("Enter the Page reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            page_faults++;
        }

        printf("After page %d: ", pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total Page faults = %d\n", page_faults);
    return 0;
}