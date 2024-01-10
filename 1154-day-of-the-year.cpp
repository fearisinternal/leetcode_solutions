class Solution
{
public:
    std::vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear(string date)
    {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));
        int ans = 0;
        for (auto i = 0; i < month - 1; i++)
        {
            ans += monthDays[i];
        }
        ans += day;
        if (year % 4 == 0 && month > 2)
            ans++;
        if (year % 100 == 0 && year % 400 != 0)
            ans--;
        return ans;
    }
};