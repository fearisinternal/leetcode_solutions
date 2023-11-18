class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        set<char>alp;
        for (auto ch : s){
            if (alp.find(ch)!=alp.end()){
                ans+=2;
                alp.erase(ch);
            }
            else
            {
                alp.insert(ch);
            }
        }
        if (!alp.empty())
        {
            ans++;
        }
        return ans;
    }
};