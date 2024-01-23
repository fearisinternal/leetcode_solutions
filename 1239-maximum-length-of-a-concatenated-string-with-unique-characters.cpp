class Solution
{
public:
    int countUnique(int index, std::vector<std::string> &arr, std::vector<std::string> &ans)
    {
        if (index >= arr.size())
            return 0;
        ans.push_back(arr[index]);
        std::unordered_map<char, int> mp;
        for (auto i : ans)
            for (auto j : i)
                mp[j]++;
        bool isUnique = true;
        for (auto m : mp)
        {
            if (m.second > 1)
                isUnique = false;
        }
        int ans1 = 0, ans2 = 0;
        if (isUnique)
        {
            ans1 = arr[index].size();
            ans1 += countUnique(index + 1, arr, ans);
        }
        ans.pop_back();
        ans2 = countUnique(index + 1, arr, ans);
        return std::max(ans1, ans2);
    }

    int maxLength(vector<string> &arr)
    {
        std::vector<std::string> ans;
        return countUnique(0, arr, ans);
    }
};