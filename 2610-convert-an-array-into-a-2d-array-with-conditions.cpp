class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        std::map<int, int> p;
        vector<vector<int>> ans;
        for (auto n : nums)
        {
            p[n]++;
        }
        while (true)
        {
            std::vector<int> temp;
            for (auto i = p.begin(); i != p.end(); i++)
            {
                if (i->second > 0)
                {
                    temp.push_back(i->first);
                    i->second--;
                }
            }
            if (temp.size() < 1)
                break;
            ans.push_back(temp);
        }
        return ans;
    }
};