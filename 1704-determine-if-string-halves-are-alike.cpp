class Solution {
public:
    std::set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool halvesAreAlike(std::string s)
    {
        int countA = 0, countB = 0;
        int half = s.size() / 2;
        for (auto i = 0; i < half; i++)
        {
            if (vowels.find(s[i]) != vowels.end())
                countA++;
            if (vowels.find(s[i + half]) != vowels.end())
                countB++;
        }
        return countA == countB;
    }
};