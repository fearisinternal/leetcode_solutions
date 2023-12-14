class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<int> sumRow(n);
        std::vector<int> sumCol(m);
        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                sumRow[i] += grid[i][j];
                sumCol[j] += grid[i][j];
            }
        }
        std::vector<std::vector<int>> diff(n, std::vector<int>(m));
        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                diff[i][j] = sumRow[i] + sumCol[j] - (m - sumRow[i]) - (n - sumCol[j]);
            }
        }
        return diff;
    }
};