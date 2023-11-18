class Solution {
public:

    bool onLine(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3){
        int x = p1[0], y = p1[1], x1 = p2[0], y1 = p2[1], x2 = p3[0], y2 = p3[1];
        return ((y - y1) * (x2 - x1) == (y2 - y1) * (x - x1));
    }

    bool checkStraightLine(vector<vector<int>>& coordinates) {
    for (auto i = 2; i<coordinates.size(); i++) {        
        if (!onLine(coordinates[0], coordinates[1], coordinates[i])) {
            return false;
        }
    }
    return true;
    }
};