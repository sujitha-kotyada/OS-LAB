#include <stdio.h>

int main() {
    int Pages[50], frames[10], times[10];
    int n, f, i, j, pos, page_faults = 0, counter = 0;
    int found;

    printf("Enter number of Pages: ");
    scanf("%d", &n);

    printf("Enter the Page reference string: \n");
    for(i = 0; i < n; i++)
        scanf("%d", &Pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frames[i] = -1;
        times[i] = 0;
    }

    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == Pages[i]) {
                counter++;
                times[j] = counter;
                found = 1;
                break;
            }
        }

        if(found == 0) {
            pos = 0;
            for(j = 1; j < f; j++) {
                if(times[j] < times[pos])
                    pos = j;
            }

            frames[pos] = Pages[i];
            counter++;
            times[pos] = counter;
            page_faults++;
        }

        printf("After Page %d: ", Pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page faults = %d\n", page_faults);
    return 0;
}