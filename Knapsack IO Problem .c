#include <stdio.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}


int knapsack(int capacity, int weights[], int values[], int n) {
    int i, w;
    int K[n + 1][capacity + 1];

    
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][capacity];
}

int main() {
    int capacity, n;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];
    int i;
    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items:\n");
    
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    int maxValue = knapsack(capacity, weights, values, n);
    printf("The maximum value that can be obtained: %d\n", maxValue);

    return 0;
}
