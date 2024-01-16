class Solution
{
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>> &matches)
    {
        std::unordered_map<int, int> players;
        for (auto s : matches)
        {
            players[s[0]] += 0;
            players[s[1]] += 1;
        }
        std::vector<std::vector<int>> ans(2);
        for (auto p : players)
        {
            if (p.second == 0)
                ans[0].push_back(p.first);
            if (p.second == 1)
                ans[1].push_back(p.first);
        }
        std::sort(ans[0].begin(), ans[0].end());
        std::sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};