class Solution
{
public:
    bool uniqueOccurrences(std::vector<int> &arr)
    {
        std::unordered_map<int, int> mp;
        for (auto i : arr)
        {
            mp[i]++;
        }
        std::set<int> s;
        for (auto m : mp)
        {
            if (s.find(m.second) != s.end())
                return false;
            s.insert(m.second);
        }
        return true;
    }
};