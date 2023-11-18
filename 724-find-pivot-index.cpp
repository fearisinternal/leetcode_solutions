class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int allSum = 0;
        for (auto num : nums){
            allSum+=num;
        }
        int sum = 0;
        for (auto index = 0; index < nums.size(); index++){
            if (sum == allSum - sum - nums[index]){
                return index;
            }
            sum+=nums[index];
        }
        return -1;
    }
};