#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications needed to multiply matrices
int matrixChainMultiplication(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0; // Cost is zero when multiplying one matrix

    // L is the chain length.
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1]; // return the minimum number of scalar multiplications
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dims[n + 1]; // dimensions of matrices
    int i;
    printf("Enter the dimensions of the matrices:\n");
    for (i = 0; i <= n; i++) {
        printf("Dimension %d: ", i);
        scanf("%d", &dims[i]);
    }

    int minScalars = matrixChainMultiplication(dims, n + 1);
    printf("Minimum number of scalar multiplications: %d\n", minScalars);

    return 0;
}
