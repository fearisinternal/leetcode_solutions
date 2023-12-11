class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        std::vector<std::vector<int>> newmat(r, std::vector<int>(c));
        int row = 0;
        int col = 0;
        for (auto i = 0; i < mat.size(); i++)
        {
            for (auto j : mat[i])
            {
                if (row == r)
                    return mat;
                newmat[row][col++] = j;
                if (col == c)
                {
                    row++;
                    col = 0;
                }
            }
        }
        if (row < r)
            return mat;
        return newmat;
    }
};