class Solution
{
public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        int mod = 1e9 + 7;
        int max_sum = 0;
        int curr_sum = 0;
        int arr_sum = 0;
        for (auto i = 0; i < arr.size(); i++)
        {
            curr_sum = std::max(arr[i], curr_sum + arr[i]);
            max_sum = std::max(max_sum, curr_sum);
            arr_sum += arr[i];
        }
        if (k > 1)
        {
            k -= 2;
            while (k > 0 && arr_sum > 0)
            {
                if (k % 2)
                {
                    curr_sum = (curr_sum + arr_sum) % mod;
                }
                arr_sum = (arr_sum * 2) % mod;
                k /= 2;
            }
            for (auto i = 0; i < arr.size(); i++)
            {
                curr_sum = std::max(arr[i], curr_sum + arr[i]);
                max_sum = std::max(max_sum, curr_sum);
            }
        }
        return max_sum % mod;
    }
};