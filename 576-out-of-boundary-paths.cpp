class Solution
{
public:
    int mod = 1e9 + 7;
    std::vector<std::vector<std::vector<int>>> dp;

    int findPath(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if (startRow < 0 || startRow >= m)
            return 1;
        if (startColumn < 0 || startColumn >= n)
            return 1;
        if (maxMove == 0)
            return 0;
        if (dp[startRow][startColumn][maxMove] != -1)
            return dp[startRow][startColumn][maxMove];

        int ans = 0;
        ans = ans + findPath(m, n, maxMove - 1, startRow + 1, startColumn);
        ans = (ans + findPath(m, n, maxMove - 1, startRow, startColumn + 1)) % mod;
        ans = (ans + findPath(m, n, maxMove - 1, startRow, startColumn - 1)) % mod;
        ans = (ans + findPath(m, n, maxMove - 1, startRow - 1, startColumn)) % mod;
        dp[startRow][startColumn][maxMove] = ans;
        return ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        dp = std::vector<std::vector<std::vector<int>>>(m, std::vector<std::vector<int>>(n, std::vector<int>(maxMove + 1, -1)));
        return findPath(m, n, maxMove, startRow, startColumn);
    }
};