class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::unordered_map<int, int> people;
        for (auto i = 0; i < n; i++)
        {
            people.insert({i + 1, 1});
        }
        for (auto pair : trust)
        {
            people[pair[1]]++;
            people[pair[0]]=0;
        }
        for (auto judge : people)
        {
            if (judge.second == n)
                return judge.first;
        }
        return -1;
    }
};