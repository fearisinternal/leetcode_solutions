class Solution {
public:
bool isValidSquare(std::vector<std::vector<char>> &board, int startN, int startM, int n, int m)
{
    std::set<int> numbers;
    for (auto i = startN; i < n; i++)
    {
        for (auto j = startM; j < m; j++)
        {
            if (board[i][j] == '.')
                continue;
            if (numbers.find(board[i][j]) != numbers.end())
            {
                return false;
            }
            numbers.insert(board[i][j]);
        }
    }
    return true;
}

bool isValidSudoku(std::vector<std::vector<char>> &board)
{
    for (auto i = 0; i < board.size(); i++)
    {
        if (!isValidSquare(board, i, 0, i + 1, board[i].size()))
            return false;

        if (!isValidSquare(board, 0, i, board.size(), i + 1))
            return false;
    }

    // check square
    for (auto i = 0; i < board.size(); i += 3)
    {
        for (auto j = 0; j < board[i].size(); j += 3)
        {
            if (!isValidSquare(board, i, j, i + 3, j + 3))
                return false;
        }
    }
    return true;
}
};