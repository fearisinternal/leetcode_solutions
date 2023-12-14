class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int count = 0;
        for (auto i = 0; i < points.size() - 1; i++)
        {
            count += std::max(std::abs(points[i][0] - points[i + 1][0]), std::abs(points[i][1] - points[i + 1][1]));
        }
        return count;
    }
};