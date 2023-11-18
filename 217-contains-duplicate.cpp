class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> map_numbers;
        for (auto i : nums) map_numbers[i]++;
        for (auto i : map_numbers) {
            if (i.second > 1) return true;
        }    
        return false;
    }
};