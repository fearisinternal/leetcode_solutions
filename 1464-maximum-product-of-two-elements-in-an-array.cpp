class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMax = std::max(nums[0], nums[1]);
        int secondMax = std::min(nums[0], nums[1]);
        for (auto i = 2; i < nums.size(); i++)
        {
            if (nums[i] > firstMax)
            {
                secondMax = firstMax;
                firstMax = nums[i];
            }
            else if (nums[i] > secondMax)
            {
                secondMax = nums[i];
            }
        }
        return (firstMax - 1) * (secondMax - 1);
    }
};