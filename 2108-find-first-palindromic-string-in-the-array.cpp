class Solution
{
public:
    std::string firstPalindrome(std::vector<std::string> &words)
    {
        for (auto &w : words)
        {
            int l = 0;
            int r = w.size() - 1;
            while (l < r)
            {
                if (w[l] != w[r])
                    break;
                l++;
                r--;
            }
            if (l >= r)
                return w;
        }
        return "";
    }
};