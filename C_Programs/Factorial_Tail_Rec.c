#include <stdio.h>
#include<stdlib.h>

long long tailFactorial(int n, long long result) {
    if (n == 0 || n == 1) {
        return result;
    }

    return tailFactorial(n - 1, n * result);
}

long long factorial(int n) {
    return tailFactorial(n, 1);
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d = %lld\n", num, factorial(num));
    }
    return 0;
}
