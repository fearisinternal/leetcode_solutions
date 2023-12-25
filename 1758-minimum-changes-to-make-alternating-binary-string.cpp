class Solution
{
public:
    int minOperations(string s)
    {
        int zeros = 0;
        int ones = 0;
        for (auto i = 0; i < s.size(); i++)
        {
            if (i % 2 && s[i] == '0')
                zeros++;
            if ((i + 1) % 2 && s[i] == '1')
                zeros++;
            if (i % 2 && s[i] == '1')
                ones++;
            if ((i + 1) % 2 && s[i] == '0')
                ones++;
        }
        return s.size() - std::max(ones, zeros);
    }
};