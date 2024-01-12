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
    int maxDiff = 0;
    int maxAncestorDiff(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxNode = root->val;
        int minNode = root->val;
        countDiff(root, minNode, maxNode);
        return maxDiff;
    }

    void countDiff(TreeNode *root, int minNode, int maxNode)
    {
        if (!root)
            return;
        maxDiff = std::max(maxDiff, std::abs(minNode - root->val));
        maxDiff = std::max(maxDiff, std::abs(maxNode - root->val));
        minNode = std::min(minNode, root->val);
        maxNode = std::max(maxNode, root->val);
        countDiff(root->left, minNode, maxNode);
        countDiff(root->right, minNode, maxNode);
    }
};