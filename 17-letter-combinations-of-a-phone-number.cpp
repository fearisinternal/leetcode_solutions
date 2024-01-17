class Solution
{
private:
    std::vector<std::string> kb = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> ans;

public:
    void createString(std::string digits, int p, std::string &str)
    {
        if (p == digits.size())
        {
            ans.push_back(str);
        }
        else
        {
            for (auto s : kb[digits[p] - '0'])
            {
                str.push_back(s);
                createString(digits, p + 1, str);
                str.pop_back();
            }
        }
    }
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.size() > 0)
        {
            std::string str;
            createString(digits, 0, str);
        }
        return ans;
    }
};