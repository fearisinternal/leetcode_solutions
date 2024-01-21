class Solution
{
public:
    int mod = 1e9 + 7;

    int sumSubarrayMins(std::vector<int> &arr)
    {
        int arr_size = arr.size();
        std::stack<int> s1, s2;
        std::vector<int64_t> left(arr_size, -1);
        std::vector<int64_t> right(arr_size, arr_size);

        for (auto i = 0; i < arr_size; ++i)
        {
            while (!s1.empty() && arr[s1.top()] > arr[i])
            {
                s1.pop();
            }
            if (!s1.empty())
                left[i] = s1.top();
            s1.push(i);
        }

        for (int i = arr_size - 1; i >= 0; --i)
        {
            while (!s2.empty() && arr[s2.top()] >= arr[i])
            {
                s2.pop();
            }
            if (!s2.empty())
                right[i] = s2.top();
            s2.push(i);
        }
        int64_t ans = 0;
        for (auto i = 0; i < arr_size; ++i)
        {
            ans = (ans + (i - left[i]) * (right[i] - i) * arr[i]) % mod;
        }
        return static_cast<int>(ans);
    }
};