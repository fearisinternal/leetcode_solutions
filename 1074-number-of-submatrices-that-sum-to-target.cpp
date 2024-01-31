class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        size_t n = matrix.size();
        size_t m = matrix[0].size();

        for (size_t row = 0; row < n; ++row)
        {
            for (size_t col = 1; col < m; col++)
            {
                matrix[row][col] += matrix[row][col - 1];
            }
        }

        int ans = 0;

        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = i; j < m; ++j)
            {
                std::unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;

                for (size_t row = 0; row < n; ++row)
                {
                    sum += matrix[row][j];
                    if (i > 0)
                        sum -= matrix[row][i - 1];
                    ans += mp[sum - target];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};