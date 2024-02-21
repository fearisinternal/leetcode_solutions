class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto i = 1; i <= nums.size(); ++i)
        {
            ans = ans ^ i;
        }
        for (auto i = 0; i < nums.size(); ++i)
        {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};