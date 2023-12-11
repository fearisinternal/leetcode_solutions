class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int beginCount = 0;
        std::vector<int> maxRow;
        for (auto i = 0; i < grid.size(); i++)
        {
            int maxNum = 0;
            for (auto j = 0; j < grid[i].size(); j++)
            {
                beginCount += grid[i][j];
                if (grid[i][j] > maxNum)
                    maxNum = grid[i][j];
            }
            maxRow.push_back(maxNum);
        }
        std::vector<int> maxCol;
        for (auto i = 0; i < grid[0].size(); i++)
        {
            int maxNum = 0;
            for (auto j = 0; j < grid.size(); j++)
            {
                if (grid[j][i] > maxNum)
                    maxNum = grid[j][i];
            }
            maxCol.push_back(maxNum);
        }
        int count = 0;
        for (auto i = 0; i < grid.size(); i++)
        {
            for (auto j = 0; j < grid[i].size(); j++)
            {
                auto temp = std::min(maxCol[j], maxRow[i]);
                grid[i][j] = std::max(grid[i][j], temp);
                count += grid[i][j];
            }
        }
        return count - beginCount;
    }
};