class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        std::vector<std::vector<int>> invert(matrix[0].size(), std::vector<int>(matrix.size()));
        for (auto i = 0; i < matrix.size(); i++)
        {
            for (auto j = 0; j < matrix[i].size(); j++)
            {
                invert[j][i] = matrix[i][j];
            }
        }
        return invert;
    }
};