class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
        for (auto i = 1; i < text1.size() + 1; ++i)
        {
            for (auto j = 1; j < text2.size() + 1; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};