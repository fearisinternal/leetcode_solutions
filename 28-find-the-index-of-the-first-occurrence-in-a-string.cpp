class Solution {
public:
    int strStr(string haystack, string needle) {
        for (auto i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                std::string str = haystack.substr(i, needle.size());
                if (str == needle)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};