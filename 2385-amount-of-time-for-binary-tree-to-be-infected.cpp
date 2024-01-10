/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxDistance = 0;
    int countLevel(TreeNode *root, int target)
    {
        int level = 0;
        if (root == nullptr)
            return 0;
        int leftLevel = countLevel(root->left, target);
        int rightLevel = countLevel(root->right, target);
        if (root->val == target)
        {
            level--;
            maxDistance = max(leftLevel, rightLevel);
        }
        else if (leftLevel >= 0 && rightLevel >= 0)
        {
            level = max(leftLevel, rightLevel) + 1;
        }
        else
        {
            int dist = std::abs(leftLevel) + std::abs(rightLevel);
            maxDistance = std::max(maxDistance, dist);
            level = std::min(leftLevel, rightLevel) - 1;
        }
        return level;
    }

    int amountOfTime(TreeNode *root, int start)
    {
        countLevel(root, start);
        return maxDistance;
    }
};