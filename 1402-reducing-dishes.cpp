class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        std::vector<int> dishes_sort = satisfaction;
        std::sort(dishes_sort.begin(), dishes_sort.end());
        std::vector<std::vector<int>> dp(2, std::vector<int>(satisfaction.size(), 0));
        int max_value = 0;
        for (auto dish = 0; dish < dishes_sort.size(); ++dish)
        {
            dp[dish % 2][0] = dishes_sort[dish];
            for (auto coef = 1; coef < dish + 1; ++coef)
            {
                dp[dish % 2][coef] = dp[(dish + 1) % 2][coef - 1] + dishes_sort[dish] * (coef + 1);
                if (max_value < dp[dish % 2][coef])
                    max_value = dp[dish % 2][coef];
            }
        }
        return max_value;
    }
};