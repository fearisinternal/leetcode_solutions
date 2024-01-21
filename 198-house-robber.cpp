class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        int rob = 0;
        int norob = 0;
        for (auto i = 0; i < nums.size(); ++i)
        {
            int itRob = norob + nums[i];
            int itNotRob = std::max(norob, rob);
            rob = itRob;
            norob = itNotRob;
        }
        return std::max(rob, norob);
    }
};