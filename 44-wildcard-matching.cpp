class Solution {
public:
    bool isMatch(string s, string p) {
    vector<vector<bool>>dp(s.size()+1, vector<bool>(p.size()+1, false));
    dp[0][0]=true;
    for (auto j=0; j<p.size()&&p[j]=='*'; j++) {
        dp[0][j+1]=true;
    }

    for (auto i = 1; i<=s.size(); i++) {
        for (auto j=1; j<=p.size(); j++) {
            if (p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else {
                dp[i][j]=dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1] == '?');
            }
        }
    }
    return dp[s.size()][p.size()];
    }
};