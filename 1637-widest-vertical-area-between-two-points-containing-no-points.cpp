class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const auto &l, const auto &r)
                { return l[0] < r[0]; });
        int widest = 0;
        for (auto i = 1; i < points.size(); i++)
        {
            int ans = points[i][0] - points[i - 1][0];
            if (widest < ans)
                widest = ans;
        }
        return widest;
    }
};