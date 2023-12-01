#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void countLevelSum(TreeNode *root, std::vector<int> &levelSum, int level)
{
    if (root == nullptr)
        return;
    int sum = 0;
    if (levelSum.size() <= level)
    {
        levelSum.push_back(root->val);
    }
    else
    {
        levelSum[level] += root->val;
    }
    countLevelSum(root->left, levelSum, level + 1);
    countLevelSum(root->right, levelSum, level + 1);
}

int deepestLeavesSum(TreeNode *root)
{
    std::vector<int> levelSum;
    countLevelSum(root, levelSum, 0);
    return levelSum[levelSum.size() - 1];
}

int main()
{
    return 0;
}
