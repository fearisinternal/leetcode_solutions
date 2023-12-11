class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int needCount = (arr.size() / 4) + 1;
        int count = 0;
        int num = 0;
        for (auto a : arr)
        {
            if (a == num)
                count++;
            else
            {
                num = a;
                count = 1;
            }
            if (count == needCount)
                return num;
        }
        return -1;
    }
};