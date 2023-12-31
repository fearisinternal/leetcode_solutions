class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l=0;
        int r = nums.size()-1;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (nums[mid]==target){
                return mid;
            }
            if (nums[l]<=nums[mid]){
                if (nums[mid]<target || target < nums[l]){
                    l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }
            else {
                if (nums[mid]>target || target > nums[r])
                {
                    r = mid-1;
                }
                else 
                {
                    l = mid +1;
                }
            }
        }
        return -1;
    }
};