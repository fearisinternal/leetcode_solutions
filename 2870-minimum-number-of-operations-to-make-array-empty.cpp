class Solution {
public:
    int minOperations(vector<int>& nums) {
        std::unordered_map<int, int> num_map;
        for (auto n : nums)
        {
            num_map[n]++;
        }
        int ans = 0;
        for (auto m : num_map)
        {
            if (m.second < 2)
                return -1;
            ans += (m.second + 2) / 3;
        }
        return ans;
    }
};