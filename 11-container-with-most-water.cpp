class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int store = (right-left)*h;
            ans = max(ans, store);
            while (height[left]<=h && left < right) {
                left++;
            }
            while (height[right]<=h && left < right) {
                right--;
            }
        }
        return ans;
    }
};