class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int first_max = 0, second_max = 0;
        int first_min = 100000, second_min = 100000;
        for (auto i : nums)
        {
            if (i > first_max)
            {
                second_max = first_max;
                first_max = i;
            }
            else if (i > second_max)
            {
                second_max = i;
            }
            if (i < first_min)
            {
                second_min = first_min;
                first_min = i;
            }
            else if (i < second_min)
            {
                second_min = i;
            }
        }
        return (first_max * second_max) - (first_min * second_min);
    }
};