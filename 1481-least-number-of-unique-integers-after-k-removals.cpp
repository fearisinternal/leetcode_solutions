class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        std::unordered_map<int, int> mp;
        for (auto &i : arr)
            mp[i]++;
        std::vector<int> nums;
        for (auto &m : mp)
            nums.push_back(m.second);
        std::sort(nums.begin(), nums.end());
        int cnt = 0;
        int ans = 0;
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (cnt + nums[i] <= k)
                cnt += nums[i];
            else
                ans++;
        }
        return ans;
    }
};