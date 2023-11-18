class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> numSums = nums;
        int point = 0;
        for (auto i = 0; i< nums.size(); i++){
            numSums[i]+=point;
            point+=nums[i];
        }
        return numSums;
    }
};