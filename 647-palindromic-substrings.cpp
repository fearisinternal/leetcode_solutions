class Solution
{
public:
    int check(std::string &str, int l, int r, int ans)
    {
        while (l >= 0 && r <= str.size())
        {
            if (str[l--] == str[r++])
                ans++;
            else
                break;
        }
        return ans;
    }
    int countSubstrings(string s)
    {
        int ans = 0;
        for (auto i = 0; i < s.size(); ++i)
        {
            ans += check(s, i, i, 0);
            ans += check(s, i, i + 1, 0);
        }
        return ans;
    }
};