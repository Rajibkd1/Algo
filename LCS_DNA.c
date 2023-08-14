#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LCSLength(const char* s1, const char* s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a 2D table to store the LCS lengths
    int dp[m + 1][n + 1];

    // Initialize the first row and first column with zeros
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    // Calculate the LCS lengths
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

void LCS(const char* s1, const char* s2, char* lcs) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a 2D table to store the LCS lengths
    int dp[m + 1][n + 1];
// Initialize the first row and first column with zeros
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    // Calculate the LCS lengths
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Construct the LCS string
    int index = dp[m][n];
    lcs[index] = '\0';  // Null-terminate the string
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
}

int main() {
    char s1[100], s2[100];
    printf("Enter the first DNA strand: ");
    scanf("%s", s1);
    printf("Enter the second DNA strand: ");
    scanf("%s", s2);

    int lcsLength = LCSLength(s1, s2);

    char lcs[100];
    LCS(s1, s2, lcs);

    printf("LCS Length: %d\n", lcsLength);
    printf("LCS: %s\n", lcs);

    return 0;
}
