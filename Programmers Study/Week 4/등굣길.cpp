#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int MOD = 1000000007;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (auto puddle : puddles)
        dp[puddle[0]][puddle[1]] = -1;
    
    dp[0][1] = 1;
    
    for (int x = 1; x <= m; x++) {
        for (int y = 1; y <= n; y++) {
            if (dp[x][y] == -1)
                dp[x][y] = 0;
            else
                dp[x][y] = (dp[x - 1][y] + dp[x][y - 1]) % MOD;
        }
    }

    return dp[m][n];
}
