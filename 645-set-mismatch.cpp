class Solution
{
public:
    std::vector<int> findErrorNums(std::vector<int> &nums)
    {
        std::unordered_set<int> s;
        for (auto i = 0; i < nums.size(); ++i)
        {
            s.insert(i + 1);
        }
        int ans = -1;
        for (auto i : nums)
        {
            if (s.find(i) != s.end())
                s.erase(i);
            else
                ans = i;
        }
        return {ans, *s.begin()};
    }
};