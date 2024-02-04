class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        std::string str = "123456789";
        std::vector<int> ans;
        for (auto i = 0; i < str.size(); ++i)
        {
            for (auto j = i + 1; j <= str.size(); ++j)
            {
                int temp = std::stoi(str.substr(i, j - i));
                if (temp >= low && temp <= high)
                    ans.push_back(temp);
            }
        }
        std::sort(ans.begin(), ans.end());
        return ans;
    }
};