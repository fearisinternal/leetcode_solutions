class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        std::vector<int> nums(n + 1);
        nums[0] = 0;
        nums[1] = 1;
        int max_num = 1;
        for (auto i = 2; i < n + 1; ++i)
        {
            int j = i / 2;
            nums[i] = nums[j];
            if (i % 2)
            {
                nums[i] += nums[j + 1];
            }
            if (nums[i] > max_num)
                max_num = nums[i];
        }
        return max_num;
    }
};