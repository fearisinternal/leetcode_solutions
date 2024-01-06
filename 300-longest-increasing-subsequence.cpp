class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 1)
            return 0;
        std::vector<int> dp(nums.size(), 1);
        for (auto i = 1; i < nums.size(); i++)
        {
            for (auto j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        int ans = dp[0];
        for (auto i : dp)
        {
            if (i > ans)
                ans = i;
        }
        return ans;
    }
};