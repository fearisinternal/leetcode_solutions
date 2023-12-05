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
class Solution {
public:
    void startEven(int &sum, TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (root->left != nullptr)
        {
            sum+=root->left->val;
        }
        if (root->right != nullptr)
        {
            sum+=root->right->val;
        }
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int sum = 0;
        sum += sumEvenGrandparent(root->left);
        sum += sumEvenGrandparent(root->right);
        if (root->val % 2 == 0)
        {
            startEven(sum, root->left);
            startEven(sum, root->right);
        }
        return sum;
    }
};