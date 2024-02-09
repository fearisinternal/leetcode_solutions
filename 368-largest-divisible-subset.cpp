class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        std::vector<int> ans;
        std::sort(nums.begin(), nums.end());
        std::vector<int> dp(nums.size(), 1);
        int maxi = 1;
        for (auto i = 1; i < nums.size(); ++i)
        {
            for (auto j = 0; j < i; ++j)
            {
                if ((nums[i] % nums[j] == 0) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    if (maxi < dp[i])
                        maxi = dp[i];
                }
            }
        }
        int num = -1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (maxi == dp[i] && (num == -1 || num % nums[i] == 0))
            {
                ans.push_back(nums[i]);
                maxi--;
                num = nums[i];
            }
        }
        return ans;
    }
};