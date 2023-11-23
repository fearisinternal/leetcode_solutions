class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t iter_nums = 0;
        for (auto i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                continue;
            }
            nums[iter_nums++] = nums[i];
        }
        return iter_nums;
    }
};