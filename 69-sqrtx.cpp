class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        long long l = 1;
        long long r = x;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            long long sum = mid * mid;
            if (sum > (long long)x) {
                r = mid - 1;
            }
            else if (sum == (long long)x)
            {
                return mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return r;
    }
};