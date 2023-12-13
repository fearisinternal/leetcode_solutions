class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        std::vector<int> cols(mat.size(), 0);
        std::vector<int> rows(mat[0].size(), 0);
        for (auto i = 0; i < mat.size(); i++)
        {
            for (auto j = 0; j < mat[i].size(); j++)
            {
                cols[i] += mat[i][j];
                rows[j] += mat[i][j];
            }
        }
        int count = 0;
        for (auto i = 0; i < mat.size(); i++)
        {
            for (auto j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] && cols[i] == 1 && rows[j] == 1)
                    count++;
            }
        }
        return count;
    }
};