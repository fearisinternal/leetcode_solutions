class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m][m];
        memset(dp, 0, sizeof(dp));
        int result = 0;
        dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];

        for (auto row = 1; row < n; ++row)
        {
            for (auto rob1 = 0; rob1 < m; ++rob1)
            {
                for (auto rob2 = 0; rob2 < m; ++rob2)
                {
                    if (rob1 > row || rob2 < m - row - 1 || rob1 > rob2)
                        continue;
                    dp[row][rob1][rob2] = dp[row - 1][rob1][rob2];

                    if (rob1 + 1 < m)
                        dp[row][rob1][rob2] = std::max(dp[row][rob1][rob2], dp[row - 1][rob1 + 1][rob2]);
                    if (rob1 + 1 < m && rob2 - 1 >= 0)
                        dp[row][rob1][rob2] = std::max(dp[row][rob1][rob2], dp[row - 1][rob1 + 1][rob2 - 1]);
                    if (rob1 + 1 < m && rob2 + 1 < m)
                        dp[row][rob1][rob2] = std::max(dp[row][rob1][rob2], dp[row - 1][rob1 + 1][rob2 + 1]);

                    if (rob1 - 1 >= 0)
                        dp[row][rob1][rob2] = std::max(dp[row][rob1][rob2], dp[row - 1][rob1 - 1][rob2]);
                    if (rob1 - 1 >= 0 && rob2 - 1 >= 0)
                        dp[row][rob1][rob2] = std::max(dp[row][rob1][rob2], dp[row - 1][rob1 - 1][rob2 - 1]);
                    if (rob1 - 1 >= 0 && rob2 + 1 < m)
                        dp[row][rob1][rob2] = std::max(dp[row][rob1][rob2], dp[row - 1][rob1 - 1][rob2 + 1]);

                    if (rob2 - 1 >= 0)
                        dp[row][rob1][rob2] = std::max(dp[row][rob1][rob2], dp[row - 1][rob1][rob2 - 1]);
                    if (rob2 - 1 < m)
                        dp[row][rob1][rob2] = std::max(dp[row][rob1][rob2], dp[row - 1][rob1][rob2 + 1]);

                    if (rob1 != rob2)
                        dp[row][rob1][rob2] += grid[row][rob1] + grid[row][rob2];
                    else
                        dp[row][rob1][rob2] += grid[row][rob1];
                    result = std::max(result, dp[row][rob1][rob2]);
                }
            }
        }
        return result;
    }
};