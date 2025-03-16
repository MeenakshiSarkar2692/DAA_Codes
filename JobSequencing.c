#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    char id;      // Job ID
    int deadline; // Job deadline
    int profit;   // Job profit
};

// Compare function used for sorting jobs by their profit in non-increasing order
int compare(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

void jobSequencing(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    char result[maxDeadline]; // Array to store the result
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = ' ';
    }

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (result[j] == ' ') {
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Job sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != ' ') {
            printf("%c ", result[i]);
        }
    }

    printf("\nTotal profit: %d\n", totalProfit);
}

int main() {
    struct Job jobs[] = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15},
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}
