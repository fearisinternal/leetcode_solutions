class Solution
{
public:
    string frequencySort(string s)
    {
        std::unordered_map<char, int> mp;
        for (auto &ss : s)
        {
            mp[ss]++;
        }
        std::multimap<int, char, std::greater<int>> dict;
        for (auto &m : mp)
        {
            dict.insert({m.second, m.first});
        }
        std::string answer = "";
        for (auto d : dict)
        {
            for (auto i = 0; i < d.first; ++i)
            {
                answer += d.second;
            }
        }
        return answer;
    }
};