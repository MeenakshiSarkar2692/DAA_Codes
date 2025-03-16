#include <stdio.h>
#include <stdlib.h>

// Structure to represent a disjoint-set node
struct DisjointSet {
    int parent;
    int rank;
};

// Function to create a new disjoint-set
struct DisjointSet* makeSet(int element) {
    struct DisjointSet* set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    set->parent = element;
    set->rank = 0;
    return set;
}

// Function to find the representative (root) of the set
int find(struct DisjointSet* sets[], int element) {
    if (sets[element]->parent != element) {
        sets[element]->parent = find(sets, sets[element]->parent); // Path compression
    }
    return sets[element]->parent;
}

// Function to union two sets based on rank
void unionSets(struct DisjointSet* sets[], int element1, int element2) {
    int root1 = find(sets, element1);
    int root2 = find(sets, element2);

    if (root1 != root2) {
        if (sets[root1]->rank < sets[root2]->rank) {
            sets[root1]->parent = root2;
        } else if (sets[root1]->rank > sets[root2]->rank) {
            sets[root2]->parent = root1;
        } else {
            sets[root2]->parent = root1;
            sets[root1]->rank++;
        }
    }
}

int main() {
    int n = 5; // Number of elements
    struct DisjointSet* sets[n];

    for (int i = 0; i < n; i++) {
        sets[i] = makeSet(i);
    }

    // Perform union operations
    unionSets(sets, 0, 1);
    unionSets(sets, 2, 3);
    unionSets(sets, 0, 4);

    // Check if elements are in the same set
    printf("Element 0 and Element 1 are in the same set: %d\n", find(sets, 0) == find(sets, 1));
    printf("Element 0 and Element 3 are in the same set: %d\n", find(sets, 0) == find(sets, 3));

    for (int i = 0; i < n; i++) {
        free(sets[i]);
    }

    return 0;
}
