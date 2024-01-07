#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int minI = -2147483648;
int maxI = 2147483647;

int numberOfArithmeticSlices(std::vector<int> &nums)
{
    int ans = 0;
    std::vector<std::unordered_map<int, int>> dp(nums.size());

    for (auto i = 1; i < nums.size(); i++)
    {
        for (auto j = 0; j < i; j++)
        {
            int64_t diff = static_cast<int64_t>(nums[i]) - nums[j];

            if (diff > maxI || diff < minI)
                continue;

            int count = std::max(dp[j][diff], 0);

            ans += count;
            dp[i][diff] += count + 1;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> nums = {0, 2000000000, -294967296};
    std::cout << numberOfArithmeticSlices(nums);
}