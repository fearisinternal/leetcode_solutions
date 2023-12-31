class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int r = nums.size();
        while (l<r) {
            int mid = (int)(l+r)/2;
            if (nums[mid]==target) {
                return mid;
            }
            if (nums[mid]<target) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        return -1;
    }
};