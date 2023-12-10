#include <iostream>
#include <algorithm>

int totalMoney(int n)
{
    int sum = 0;
    int start = 1;
    int days = 7;
    while (n > 0)
    {
        if (n < 7)
            days = n;
        sum += (days * (start + start + days - 1)) / 2;
        n -= days;
        start++;
    }
    return sum;
}

int main()
{
    std::cout << totalMoney(20);
}