#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int S, int N, int sizes[], int values[]) {
    // Create a 2D table to store the maximum values
    int dp[N + 1][S + 1];

    // Initialize the first row with zeros
    for (int j = 0; j <= S; j++) {
        dp[0][j] = 0;
    }

    // Calculate the maximum values
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (sizes[i - 1] <= j)
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - sizes[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[N][S];
}

int main() {
    int S, N;
    scanf("%d %d", &S, &N);

    int sizes[N];
    int values[N];

    for (int i = 0; i < N; i++) {
        int size, value;
        scanf("%d %d", &size, &value);
        sizes[i] = size;
        values[i] = value;
    }

    int maxTotalValue = knapsack(S, N, sizes, values);

    printf("Maximum Total Value: %d\n", maxTotalValue);

    return 0;
}
