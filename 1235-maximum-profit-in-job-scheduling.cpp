class Solution
{
public:
    int search(std::vector<std::tuple<int, int, int>> &jobs, int time, int target)
    {
        int l = 0;
        int r = time;
        while (l < r)
        {
            int mid = (int)(l + r) / 2;
            if (std::get<0>(jobs[mid]) <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }

    int jobScheduling(std::vector<int> &startTime, std::vector<int> &endTime, std::vector<int> &profit)
    {
        std::vector<std::tuple<int, int, int>> jobs;
        for (int i = 0; i < profit.size(); ++i)
        {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        std::sort(jobs.begin(), jobs.end());

        std::vector<int> dp(jobs.size() + 1);
        for (auto i = 0; i < jobs.size(); ++i)
        {
            int index = search(jobs, i, std::get<1>(jobs[i]));
            dp[i + 1] = std::max(dp[i], dp[index] + std::get<2>(jobs[i]));
        }
        return dp[jobs.size()];
    }
};