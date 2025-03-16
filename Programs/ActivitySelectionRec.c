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

// Recursive function to select activities
void selectActivities(struct Activity activities[], int n, int i) {
    // Find the next activity that doesn't overlap with the current one
    int j = i + 1;
    while (j < n && activities[j].start < activities[i].finish) {
        j++;
    }

    // If we find a non-overlapping activity, select it
    if (j < n) {
        printf("Activity %d: Start time = %d, Finish time = %d\n", j, activities[j].start, activities[j].finish);
        selectActivities(activities, n, j);
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

    // Sort the activities by finish time
    qsort(activities, n, sizeof(struct Activity), compare);

    printf("Selected activities:\n");
    printf("Activity 0: Start time = %d, Finish time = %d\n", activities[0].start, activities[0].finish);
    selectActivities(activities, n, 0);

    return 0;
}

