#include <iostream>
#include <vector>

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> &matrix)
{
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

int main()
{
    return 0;
}
