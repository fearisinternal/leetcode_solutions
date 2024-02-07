class Solution
{
public:
    int firstUniqChar(string s)
    {
        std::unordered_map<char, int> mp;
        for (auto i : s)
        {
            mp[i]++;
        }
        int ans = -1;
        for (auto i = 0; i < s.size(); ++i)
        {
            if (mp[s[i]] == 1)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};