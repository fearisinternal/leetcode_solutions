class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            int local_max = 0;
            int max_sum = 0;
            for (int j = 1; j <= k && i - j >= 0; ++j)
            {
                local_max = std::max(local_max, arr[i - j]);
                max_sum = std::max(max_sum, dp[i - j] + local_max * j);
            }
            dp[i] = max_sum;
        }
        return dp[n];
    }
};