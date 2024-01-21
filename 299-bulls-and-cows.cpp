class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int a = 0;
        int b = 0;
        std::unordered_map<char, int> sec;
        std::unordered_map<char, int> gue;
        for (auto i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
                a++;
            else
            {
                sec[secret[i]]++;
                gue[guess[i]]++;
            }
        }
        for (auto i : sec)
        {
            b += std::min(i.second, gue[i.first]);
        }
        std::string s = std::to_string(a) + "A" + std::to_string(b) + "B";
        return s;
    }
};