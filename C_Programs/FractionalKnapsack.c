#include <stdio.h>

// Structure to represent an item
struct Item {
    int weight;
    int profit;
};

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    double totalProfit = 0.0; // Total value in the knapsack
    int currentWeight = 0;  // Current weight in the knapsack
    
    // Iterate through the items
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // If the current item fits entirely in the knapsack, take it
            totalProfit += items[i].profit;
            currentWeight += items[i].weight;
        } else {
            // If the current item can only be taken partially, take a fraction of it
            double fraction = (double)(capacity - currentWeight) / items[i].weight;
            totalProfit += items[i].profit * fraction;
            break; // The knapsack is now full, so we can exit the loop
        }
    }
    
    return totalProfit;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter the weight of item %d:",i);
        scanf("%d", &items[i].weight);
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the profit of item %d:",i);
        scanf("%d", &items[i].profit);
    }
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);
    
    double maxProfit = fractionalKnapsack(items, n, capacity);
    printf("The maximum profit that can be obtained is: %.2lf\n", maxProfit);
    
    return 0;
}

