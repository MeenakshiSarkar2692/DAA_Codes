#include <stdio.h>

double fractionalKnapsack(int weights[], int profits[], int n, int capacity) {
    double totalProfit = 0.0; 
    double valuePerWeight[n];
    for (int i = 0; i < n; i++) {
        valuePerWeight[i] = (double)profits[i] / weights[i];
    }

    while (capacity > 0) {
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (valuePerWeight[i] > valuePerWeight[maxIndex]) {
                maxIndex = i;
            }
        }
        int quantity = (capacity < weights[maxIndex]) ? capacity : weights[maxIndex];
        totalProfit += valuePerWeight[maxIndex] * quantity;
        capacity -= quantity;
        valuePerWeight[maxIndex] = 0;
    }

    return totalProfit;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], profits[n];

    printf("Enter the weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the profits of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    double maxProfit = fractionalKnapsack(weights, profits, n, capacity);
    printf("The maximum profit that can be obtained is: %.2lf\n", maxProfit);

    return 0;
}
