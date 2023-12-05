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
    void countSum(int &sum, int &count, int &averageCount, TreeNode *root)
    {
        if (root == nullptr)
            return;
        int leftSum = 0;
        int leftCount = 0;
        countSum(leftSum, leftCount, averageCount, root->left);
        int rightSum = 0;
        int rightCount = 0;
        countSum(rightSum, rightCount, averageCount, root->right);
        sum = leftSum + rightSum + root->val;
        count = leftCount + rightCount + 1;
        if (sum/count == root->val) averageCount++;
    }

    int averageOfSubtree(TreeNode *root)
    {
        int sum = 0;
        int count = 0;
        int averageCount = 0;
        countSum(sum, count, averageCount, root);
        return averageCount;
    }
};