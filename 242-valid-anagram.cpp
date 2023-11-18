class Solution {
public:
    void create_map(std::map<char, int>& m, std::string str)
    {
        for (auto& s : str)
        {
            if (m.find(s)==m.end())
            {
                m.insert(std::make_pair(s, 1));
            }
            else
            {
                m.find(s)->second++;
            }
        }
    }
    
    bool isAnagram(string s, string t) {
        std::map<char, int>map_s;
        std::map<char, int>map_t;
        create_map(map_s, s);
        create_map(map_t, t);
        return (map_s == map_t);
    }
};