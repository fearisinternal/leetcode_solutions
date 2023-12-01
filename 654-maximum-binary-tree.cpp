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
    TreeNode *getAnswer(std::vector<int> &nums, int l, int r)
    {
        if (r < l)
            return nullptr;
        int i_max = l;
        for (auto i = l + 1; i < r + 1; i++)
        {
            if (nums[i] > nums[i_max])
                i_max = i;
        }
        TreeNode *root = new TreeNode(nums[i_max]);
        root->left = getAnswer(nums, l, i_max - 1);
        root->right = getAnswer(nums, i_max + 1, r);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(std::vector<int> &nums)
    {
        return getAnswer(nums, 0, nums.size() - 1);
    }
};