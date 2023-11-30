class Solution {
public:
    int minInsertions(string s) {
        int lenght = (int)s.size();
        std::vector<std::vector<int>> dp(2, std::vector<int>(lenght + 1, 0));
        for (auto start = 1; start < lenght + 1; ++start)
        {
            for (auto i = 1; i < lenght + 1; ++i)
            {

                if (s[start - 1] == s[lenght - i])
                {
                    dp[start % 2][i] = dp[(start - 1) % 2][i - 1] + 1;
                }
                else
                {
                    dp[start % 2][i] = std::max(dp[start % 2][i - 1], dp[(start - 1) % 2][i]);
                }
            }
        }
        int answer = lenght - dp[(lenght) % 2][lenght];
        return answer;
    }
};