class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        for (auto str : s)
        {
            if (str == '1') ones++;
        }
        int zeros = 0;
        int maxi = 0;
        for (auto i = 0; i < s.size()-1; i++)
        {
            if (s[i] == '1') ones--;
            if (s[i] == '0') zeros++;
            if (maxi < ones+zeros) maxi = ones+zeros;
        }
        return maxi;
    }
};