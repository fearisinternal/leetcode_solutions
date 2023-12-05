class Solution {
public:
    bool dfs(std::vector<std::vector<int>> &G, std::vector<bool> &visited, int from, int to)
    {
        if (from == to)
            return true;
        visited[from] = true;
        for (auto v : G[from])
        {
            if (!visited[v] && dfs(G, visited, v, to))
                return true;
        }
        return false;
    }

    bool validPath(int n, std::vector<std::vector<int>> &edges, int source, int destination)
    {
        std::vector<std::vector<int>> G(n, std::vector<int>());
        std::vector<bool> visited(n, false);
        for (auto edge : edges)
        {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        return dfs(G, visited, source, destination);
    }
};