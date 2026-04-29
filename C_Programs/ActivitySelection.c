#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Compare function used for sorting activities by their finish times
int compare(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

void printMaxActivities(struct Activity activities[], int n) {
    // Sort the activities by finish time
    qsort(activities, n, sizeof(struct Activity), compare);

    printf("Selected activities:\n");

    // The first activity is always selected
    int i = 0;
    printf("Activity %d: Start time = %d, Finish time = %d\n", i, activities[i].start, activities[i].finish);

    // Consider the rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity has a start time greater than or equal to the finish
        // time of the previously selected activity, then select it
        if (activities[j].start >= activities[i].finish) {
            printf("Activity %d: Start time = %d, Finish time = %d\n", j, activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

int main() {
    struct Activity activities[] = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 8},
        {5, 9},
        {6, 10},
        {8, 11},
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    printMaxActivities(activities, n);

    return 0;
}