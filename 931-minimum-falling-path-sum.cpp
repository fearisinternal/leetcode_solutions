class Solution
{
public:
    int maxi = 1000000000;
    int minFallingPathSum(std::vector<std::vector<int>> &matrix)
    {
        int n = matrix.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for (auto i = 0; i < n; ++i)
        {
            dp[0][i] = matrix[0][i];
        }
        for (auto i = 1; i < n; ++i)
        {
            for (auto j = 0; j < n; ++j)
            {
                int l = maxi;
                int r = maxi;
                if (j - 1 >= 0)
                {
                    l = dp[i - 1][j - 1];
                }
                if (j + 1 < n)
                {
                    r = dp[i - 1][j + 1];
                }
                dp[i][j] = matrix[i][j] + std::min(dp[i - 1][j], std::min(l, r));
            }
        }
        int ans = dp[n - 1][0];
        for (auto i = 1; i < n; i++)
        {
            ans = std::min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};