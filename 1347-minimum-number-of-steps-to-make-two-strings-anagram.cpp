class Solution {
public:
    int minSteps(string s, string t) {
        std::map<char,int>dictionary;
        for (auto str : s)
        {
            dictionary[str]++;
        }
        for (auto str : t)
        {
            dictionary[str]--;
        }
        int ans = 0;
        for (auto d : dictionary)
        {
            ans+=std::abs(d.second);
        }
        return ans/2;
    }
};