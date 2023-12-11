class Solution {
public:
    void countPaths(std::vector<std::vector<int>> &grid, int i, int j, int allCount, int count, int &ans)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1)
            return;
        if (grid[i][j] == 2)
        {
            if (count == allCount)
                ans++;
            return;
        }
        grid[i][j] = -1;
        count++;
        countPaths(grid, i - 1, j, allCount, count, ans);
        countPaths(grid, i + 1, j, allCount, count, ans);
        countPaths(grid, i, j - 1, allCount, count, ans);
        countPaths(grid, i, j + 1, allCount, count, ans);
        grid[i][j] = 0;
    }

    int uniquePathsIII(std::vector<std::vector<int>> &grid)
    {
        int allCount = 1;
        int startI = 0;
        int startJ = 0;
        for (auto i = 0; i < grid.size(); i++)
        {
            for (auto j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                    allCount++;
                if (grid[i][j] == 1)
                {
                    startI = i;
                    startJ = j;
                }
            }
        }
        int answer = 0;
        countPaths(grid, startI, startJ, allCount, 0, answer);
        return answer;
    }
};