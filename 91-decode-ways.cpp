class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0')
            return 0;
        int n = s.size();
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (auto i = 2; i <= s.size(); i++)
        {
            if (s[i - 1] - '0' != 0)
                dp[i] += dp[i - 1];
            if (s.substr(i - 2, 2) >= "10" && s.substr(i - 2, 2) <= "26")
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};