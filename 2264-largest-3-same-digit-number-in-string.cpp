class Solution {
public:
    string largestGoodInteger(string num) {
        std::string largeNum = "";
        for (auto i = 2; i < num.size(); i++)
        {
            if (num[i - 2] == num[i - 1] && num[i - 1] == num[i])
            {
                if (num.substr(i - 2, 3) > largeNum)
                {
                    largeNum = num.substr(i - 2, 3);
                }
            }
        }
        return largeNum;
    }
};