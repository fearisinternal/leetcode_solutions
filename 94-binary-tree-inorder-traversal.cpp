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

    void addPoints(TreeNode* curr, std::vector<int> &points)
    {
        if (curr == nullptr) return;
        addPoints(curr->left, points);
        points.push_back(curr->val);
        addPoints(curr->right, points);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int>points;
        addPoints(root, points);
        return points;
    }
};