class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ss = "";
        for (auto point = 0; point< strs[0].size(); point++) {
            for (auto st = 1; st<strs.size(); st++) {
                if (strs[st].size() < point || strs[0][point] != strs[st][point]) {
                    return ss;
                }
            }
            ss+=strs[0][point];
        }
        return ss;
    }
};