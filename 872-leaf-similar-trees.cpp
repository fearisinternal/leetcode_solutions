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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        std::vector<int> tree1;
        std::vector<int> tree2;
        createTreeVector(root1, tree1);
        createTreeVector(root2, tree2);
        return tree1 == tree2;
    }

    void createTreeVector(TreeNode *root, std::vector<int> &tree)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            tree.push_back(root->val);
            return;
        }
        createTreeVector(root->left, tree);
        createTreeVector(root->right, tree);
    }
};