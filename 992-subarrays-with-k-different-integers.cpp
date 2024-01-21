class Solution
{
public:
    int countSubarrays(std::vector<int> nums, int k)
    {
        std::unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        int count = 0;
        while (i < nums.size())
        {
            mp[nums[i]]++;
            while (mp.size() > k)
            {
                auto point = mp.find(nums[j]);
                point->second--;
                if (point->second == 0)
                    mp.erase(point);
                j++;
            }
            count += i - j + 1;
            i++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return countSubarrays(nums, k) - countSubarrays(nums, k - 1);
    }
};