#include <vector>
#include <iostream>

int buyChoco(std::vector<int> &prices, int money)
{
    int firstMin = 101;
    int secondMin = 101;
    for (auto i : prices)
    {
        if (i < firstMin)
        {
            secondMin = firstMin;
            firstMin = i;
        }
        else if (i < secondMin)
        {
            secondMin = i;
        }
    }
    int count = money - firstMin - secondMin;
    if (count >= 0)
        return count;
    return money;
}

int main()
{
    std::vector<int> prices = {3,2,3};
    int money = 3;
    std::cout << buyChoco(prices, money);
}