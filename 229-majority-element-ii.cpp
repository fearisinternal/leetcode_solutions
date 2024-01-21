class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums;
        int count1 = 0;
        int count2 = 0;
        int p1 = -1000000001;
        int p2 = -1000000001;
        for (auto p : nums)
        {
            if (count1 == 0 && p2 != p)
            {
                p1 = p;
                count1 = 1;
            }
            else if (count2 == 0 && p1 != p)
            {
                p2 = p;
                count2 = 1;
            }
            else if (p == p1)
                count1++;
            else if (p == p2)
                count2++;
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (auto p : nums)
        {
            if (p == p1)
                count1++;
            else if (p == p2)
                count2++;
        }
        std::vector<int> ans;
        if (count1 > nums.size() / 3)
            ans.push_back(p1);
        if (count2 > nums.size() / 3)
            ans.push_back(p2);
        return ans;
    }
};