#include <stdio.h>

int main() {
    int n, f; // n = number of pages, f = number of frames
    int pages[100], frames[20], recent[20];
    int page_faults = 0, page_hits = 0;
    int time = 0, found, lru, min_time;

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

    // Initialize frames to empty (-1) and usage time to 0
    for (int i = 0; i < f; i++) {
        frames[i] = -1;
        recent[i] = 0;
    }

    printf("\nPage\t\tFrames\t\tStatus\n");
    printf("-----------------------------------------------\n");

    // Main loop for each page request
    for (int i = 0; i < n; i++) {
        found = 0;
        time++; // Increment "global time" each page access

        // Check if page is already in any frame
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;           // Page hit
                page_hits++;
                recent[j] = time;    // Update its "last used" time
                break;
            }
        }

        // Print current page request
        printf("%2d\t\t", pages[i]);

        // If page not found → replace least recently used
        if (!found) {
            // Find LRU page (smallest recent[] value)
            lru = 0;
            min_time = recent[0];
            for (int j = 1; j < f; j++) {
                if (recent[j] < min_time) {
                    min_time = recent[j];
                    lru = j;
                }
            }

            // Replace that frame with new page
            frames[lru] = pages[i];
            recent[lru] = time;
            page_faults++;

            // Print frames
            for (int j = 0; j < f; j++) {
                if (frames[j] != -1)
                    printf("%2d ", frames[j]);
                else
                    printf("- ");
            }
            printf("\tMiss\n");
        }
        else {
            // Print frames (unchanged)
            for (int j = 0; j < f; j++) {
                if (frames[j] != -1)
                    printf("%2d ", frames[j]);
                else
                    printf("- ");
            }
            printf("\tHit\n");
        }
    }

    printf("-----------------------------------------------\n");
    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", page_hits);
    printf("Page Fault Rate: %.2f%%\n", (page_faults * 100.0) / n);
    printf("Page Hit Rate: %.2f%%\n", (page_hits * 100.0) / n);

    return 0;
}

