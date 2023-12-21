class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        std::map<std::string, int> points;
        for (auto path : paths)
        {
            points[path[0]]--;
            points[path[1]]++;
        }
        for (auto i : points)
        {
            if (i.second > 0) return i.first;
        }
        return "";
    }
};