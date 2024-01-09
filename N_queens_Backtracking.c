#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int sum)
{
    int dp[sum + 1];
    int usedCoins[sum + 1][n];
    dp[0] = 0;

    for (int i = 1; i <= sum; i++)
        dp[i] = INT_MAX;

    for (int i = 0; i <= sum; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                    for (int k = 0; k < n; k++) {
                        usedCoins[i][k] = usedCoins[i - coins[j]][k];
                    }
                    usedCoins[i][j]++;
                }
            }
        }
    }

    printf("Coins used: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", usedCoins[sum][i]);
    }
    printf("\n");

    return dp[sum];
}

int main()
{
    int coins[] = { 1, 2, 3 };
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 5;

    printf("Minimum number of coins: %d\n", minCoins(coins, n, sum));
    return 0;
}
