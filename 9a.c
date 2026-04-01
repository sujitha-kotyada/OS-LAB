#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k, pos, page_faults = 0;
    int found, farthest, index;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames with -1
    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    // Optimal Page Replacement Logic
    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page already in frame
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If page not found, replace using Optimal
        if(found == 0) {
            pos = -1;

            // Check for empty frame
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find optimal page to replace
            if(pos == -1) {
                farthest = i + 1;
                pos = -1;

                for(j = 0; j < f; j++) {
                    index = -1;

                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {
                            index = k;
                            break;
                        }
                    }

                    if(index == -1) {
                        pos = j;
                        break;
                    }

                    if(index > farthest) {
                        farthest = index;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            page_faults++;
        }

        // Print frames after every page reference
        printf("After page %d: ", pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}