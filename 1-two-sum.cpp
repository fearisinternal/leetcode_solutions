class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>numbs;
        int i = 0, j = 0;
        for (auto num : nums) {
            if (numbs.find(target-num)!=numbs.end()){
                i = numbs.find(target-num)->second;
                break;
            }       
            else{
                numbs.insert({num, j});
            }
            j++;
        }
        return {i,j};
    }
};