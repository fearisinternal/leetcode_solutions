class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        std::vector<int> ans(n, 0);
        std::vector<int64_t> times(n, 0);

        std::sort(meetings.begin(), meetings.end());
        for (auto i = 0; i < meetings.size(); ++i)
        {
            int isMeet = false;
            int indMin = 0;
            for (auto j = 0; j < n; ++j)
            {
                if (times[j] < times[indMin])
                    indMin = j;
                if (times[j] <= meetings[i][0])
                {
                    isMeet = true;
                    ans[j]++;
                    times[j] = meetings[i][1];
                    break;
                }
            }
            if (!isMeet)
            {
                ans[indMin]++;
                times[indMin] += (meetings[i][1] - meetings[i][0]);
            }
        }
        int indMax = 0;
        for (auto i = 1; i < n; ++i)
        {
            if (ans[i] > ans[indMax])
                indMax = i;
        }
        return indMax;
    }
};