class Solution
{
public:
    const int mod = 1e9 + 7;
    int kInversePairs(int n, int k)
    {
        std::vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for (size_t i = 2; i <= n; ++i)
        {
            for (size_t j = 1; j <= k; ++j)
            {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
            for (size_t j = k; j >= i; --j)
            {
                dp[j] = (dp[j] - dp[j - i] + mod) % mod;
            }
        }
        return dp[k];
    }
};