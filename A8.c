
#include <stdio.h>

int main() {
    int n, f, pages[100], frames[20];
    int page_faults = 0, page_hits = 0;
    int pos = 0; // To track which frame to replace next
    int found;

    // Input: number of pages
    printf("Enter number of pages: ");
    scanf("%d", &n);

    // Input: page reference string
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    // Input: number of frames
    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize all frames to empty (-1)
    for (int i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\t\tFrames\t\tStatus\n");
    printf("--------------------------------------------\n");

    // Loop through each page request
    for (int i = 0; i < n; i++) {
        found = 0;

        // Check if page already exists in any frame
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1; // Page hit
                page_hits++;
                break;
            }
        }

        // Print current page number
        printf("%2d\t\t", pages[i]);

        // If page not found → page fault → replace oldest page
        if (!found) {
            frames[pos] = pages[i];       // Replace page
            pos = (pos + 1) % f;          // Move to next frame (circular)
            page_faults++;

            // Print frames after replacement
            for (int j = 0; j < f; j++) {
                if (frames[j] != -1)
                    printf("%2d ", frames[j]);
                else
                    printf("- ");
            }
            printf("\tMiss\n");
        }
        else {
            // Print frames (unchanged) for a page hit
            for (int j = 0; j < f; j++) {
                if (frames[j] != -1)
                    printf("%2d ", frames[j]);
                else
                    printf("- ");
            }
            printf("\tHit\n");
        }
    }

    printf("--------------------------------------------\n");
    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", page_hits);
    printf("Page Fault Rate: %.2f%%\n", (page_faults * 100.0) / n);
    printf("Page Hit Rate: %.2f%%\n", (page_hits * 100.0) / n);

    return 0;
}
