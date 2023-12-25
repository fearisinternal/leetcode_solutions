class Solution {
public:
    bool isPathCrossing(string path) {
        std::set<std::pair<int, int>> points;
        int x = 0;
        int y = 0;
        points.insert({x,y});
        for (auto s : path)
        {
            if (s == 'N')
                y++;
            else if (s == 'S')
                y--;
            else if (s == 'E')
                x++;
            else if (s == 'W')
                x--;
            if (points.find({x, y}) != points.end())
                return true;
            points.insert({x, y});
        }
        return false;
    }
};