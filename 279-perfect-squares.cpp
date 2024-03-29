class Solution
{
public:
    int numSquares(int n)
    {
        std::vector<int> dp(n + 1, 100000);
        dp[0] = 0;
        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 1; j * j <= i; ++j)
            {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};