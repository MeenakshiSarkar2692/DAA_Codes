#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications needed to multiply a sequence of matrices
int matrixChainMultiplication(int dims[], int n) {
    int m[n][n];

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int cost = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int dims[] = {10, 30, 5, 60};
    int n = sizeof(dims) / sizeof(dims[0]);

    int minMultiplications = matrixChainMultiplication(dims, n);

    printf("Minimum number of multiplications: %d\n", minMultiplications);

    return 0;
}
