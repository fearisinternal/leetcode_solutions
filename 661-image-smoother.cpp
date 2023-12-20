class Solution {
public:
    int isExist(std::vector<std::vector<int>> &img, int i, int j, int &point)
    {
        if (i >= 0 && j >= 0 && i < img.size() && j < img[0].size())
        {
            point += img[i][j];
            return 1;
        }
        return 0;
    }

    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>> &img)
    {
        std::vector<std::vector<int>> ans(img.size(), std::vector<int>(img[0].size(), 0));
        for (auto i = 0; i < img.size(); ++i)
        {
            for (auto j = 0; j < img[0].size(); ++j)
            {
                int count = 1;
                ans[i][j] = img[i][j];
                count += isExist(img, i-1, j - 1, ans[i][j]);
                count += isExist(img, i - 1, j, ans[i][j]);
                count += isExist(img, i - 1, j + 1, ans[i][j]);
                count += isExist(img, i, j - 1, ans[i][j]);
                count += isExist(img, i, j + 1, ans[i][j]);
                count += isExist(img, i + 1, j - 1, ans[i][j]);
                count += isExist(img, i + 1, j, ans[i][j]);
                count += isExist(img, i + 1, j + 1, ans[i][j]);
                ans[i][j]/=count;
            }
        }
        return ans;
    }
};о