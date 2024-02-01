class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        for (auto i = 0; i < nums.size(); i += 3)
        {
            if (abs(nums[i] - nums[i + 1]) > k)
                return {};
            if (abs(nums[i] - nums[i + 2]) > k)
                return {};
            if (abs(nums[i + 2] - nums[i + 1]) > k)
                return {};
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};