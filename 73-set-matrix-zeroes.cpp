class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        std::unordered_set<int> rows;
        std::unordered_set<int> cols;
        for (auto i = 0; i < matrix.size(); i++)
        {
            for (auto j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (auto i = 0; i < matrix.size(); i++)
        {
            for (auto j = 0; j < matrix[i].size(); j++)
            {
                if (rows.find(i) != rows.end() || cols.find(j) != cols.end())
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};