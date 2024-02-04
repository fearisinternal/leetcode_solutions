class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() == 0 || t.size() == 0)
            return "";

        std::unordered_map<char, int> mt;
        for (auto tt : t)
        {
            mt[tt]++;
        }

        int l = 0;
        int r = 0;
        int count = 0;

        int ans_c = -1;
        int ans_l = 0;
        std::unordered_map<char, int> ms;

        while (r < s.size())
        {
            char point = s[r];
            ms[point]++;
            if (mt.find(point) != mt.end() && ms[point] == mt[point])
            {
                count++;
            }
            while (l <= r && count == mt.size())
            {
                point = s[l];
                if (ans_c == -1 || r - l + 1 < ans_c)
                {
                    ans_c = r - l + 1;
                    ans_l = l;
                }
                ms[point]--;
                if (mt.find(point) != mt.end() && ms[point] < mt[point])
                {
                    count--;
                }
                l++;
            }
            r++;
        }
        if (ans_c == -1)
            return "";
        return s.substr(ans_l, ans_c);
    }
};