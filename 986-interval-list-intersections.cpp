class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    vector<vector<int>> ansSequence;
    for (auto i = 0, j = 0; i<firstList.size() && j<secondList.size();) {
        int start = max(firstList[i][0], secondList[j][0]);
        int finish = min(firstList[i][1], secondList[j][1]);
        if (start <= finish) {
            ansSequence.push_back({start, finish});
        }
        if (finish == firstList[i][1])  {
            i++;
        }
        else {
            j++;
        }
    }
    return ansSequence;
}
};