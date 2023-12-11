class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxCount = 0;
        for (auto acc : accounts)
        {
            int count = 0;
            for (auto wealth : acc)
            {
                count += wealth;
            }
            if (maxCount < count)
                maxCount = count;
        }
        return maxCount;
    }
};