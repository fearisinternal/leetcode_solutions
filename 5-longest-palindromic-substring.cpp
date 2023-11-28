class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        int max_size = 1;
        int first = 0;

        for (auto i = 0; i < n; ++i)
        {
            dp[i][i] = true;
            for (auto j = 0; j < i; ++j)
            {
                if (s[i] == s[j] && (i - j < 3 || dp[i - 1][j + 1]))
                {
                    dp[i][j] = true;
                    if (i - j + 1 > max_size)
                    {
                        max_size = i - j + 1;
                        first = j;
                    }
                }
            }
        }
        return s.substr(first, max_size);
    }
};