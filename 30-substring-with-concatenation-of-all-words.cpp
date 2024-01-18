class Solution
{
public:
    bool checkLine(std::unordered_map<std::string, int> mp, std::string s, int p)
    {
        int word_size = mp.begin()->first.size();
        for (auto i = 0; i < s.size(); i += word_size)
        {
            std::string word = s.substr(i, word_size);
            if (mp.find(word) == mp.end())
                return false;
            if (--mp[word] < 0)
                return false;
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string> &words)
    {
        int words_size = words[0].size();
        int words_lenght = words_size * words.size();
        if (s.size() < words_lenght)
            return {};
        std::unordered_map<std::string, int> mp;
        for (auto w : words)
        {
            mp[w]++;
        }
        std::vector<int> ans;
        for (auto i = 0; i <= s.size() - words_lenght; i++)
        {
            if (checkLine(mp, s.substr(i, words_lenght), i))
                ans.push_back(i);
        }
        return ans;
    }
};