class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int i = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int count = 0;
        for (; i < g.size(); i++)
        {
            while (count < s.size() && s[count] < g[i])
            {
                count++;
            }
            if (count >= s.size())
                return i;
            count++;
        }
        return i;
    }
};