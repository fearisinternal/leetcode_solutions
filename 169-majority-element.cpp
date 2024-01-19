class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int ans = 0;
        for (auto i : nums)
        {
            if (count == 0)
            {
                ans = i;
            }
            if (i == ans)
                count++;
            else
                count--;
        }
        return ans;
    }
};