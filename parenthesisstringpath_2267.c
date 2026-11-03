#include <stdbool.h>
#include <string.h>
bool hasValidPath(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int pathLength = m + n - 1;
    if (pathLength % 2 != 0) {
        return false;
    }
    static bool dp[100][100][201];
    memset(dp, 0, sizeof(dp));
    if (grid[0][0] == '(') {
        dp[0][0][1] = true;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int change = grid[i][j] == '(' ? 1 : -1;
            for (int balance = 0; balance <= pathLength; balance++) {
                int previousBalance = balance - change;

                if (previousBalance < 0) {
                    continue;
                }
                if ((i > 0 && dp[i - 1][j][previousBalance]) ||
                    (j > 0 && dp[i][j - 1][previousBalance])) {
                    dp[i][j][balance] = true;
                }
            }
        }
    }
    return dp[m - 1][n - 1][0];
}
