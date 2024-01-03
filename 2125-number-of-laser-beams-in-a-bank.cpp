class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int count_prev = 0;
        int count_curr = 0;
        int ans = 0;
        for (auto str : bank)
        {
            count_curr = 0;
            for (auto s : str)
            {
                if (s == '1')
                    count_curr++;
            }
            if (count_prev == 0)
            {
                count_prev = count_curr;
                continue;
            }
            if (count_curr == 0)
            {
                continue;
            }
            ans += (count_prev * count_curr);
            count_prev = count_curr;
        }
        return ans;
    }
};