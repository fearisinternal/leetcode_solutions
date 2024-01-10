class Solution
{
public:
    int mod = 1000000007;

    int numRollsToTarget(int n, int k, int target)
    {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1));
        dp[0][0] = 1;
        for (auto i = 1; i <= n; i++)
        {
            for (auto j = i; j <= std::min(i * k, target); j++)
            {
                for (auto d = 1; d <= std::min(k, j); d++)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - d]) % mod;
                }
            }
        }
        return dp[n][target];
    }
};