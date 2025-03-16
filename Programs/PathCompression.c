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

// Function to find the representative (root) of the set with path compression
int find(struct DisjointSet* sets[], int element) {
    if (sets[element]->parent != element) {
        sets[element]->parent = find(sets, sets[element]->parent); // Path compression
    }
    return sets[element]->parent;
}

int main() {
    int n = 5; // Number of elements
    struct DisjointSet* sets[n];

    for (int i = 0; i < n; i++) {
        sets[i] = makeSet(i);
    }

    // Perform find operations with path compression
    int root = find(sets, 3);
    printf("The representative (root) of element 3 is %d\n", root);

    for (int i = 0; i < n; i++) {
        free(sets[i]);
    }

    return 0;
}
