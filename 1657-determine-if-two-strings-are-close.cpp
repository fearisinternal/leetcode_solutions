class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.length() != word2.length())
            return false;
        std::vector<int> w1(26, 0);
        std::vector<int> w2(26, 0);
        for (auto s : word1)
        {
            w1[s - 'a']++;
        }
        for (auto s : word2)
        {
            w2[s - 'a']++;
        }
        for (auto i = 0; i < w1.size(); i++)
        {
            if ((w1[i] == 0 && w2[i] != 0) || (w2[i] == 0 && w1[i] != 0))
                return false;
        }
        std::sort(w1.begin(), w1.end());
        std::sort(w2.begin(), w2.end());
        for (auto i = 0; i < w1.size(); i++)
        {
            if (w1[i] != w2[i])
                return false;
        }
        return true;
    }
};