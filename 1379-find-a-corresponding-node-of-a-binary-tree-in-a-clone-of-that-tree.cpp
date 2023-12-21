/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *getTarget(TreeNode *target, TreeNode *curr)
    {
        if (curr == NULL)
            return NULL;
        if (target->val == curr->val)
        {
            return curr;
        }
        else
        {
            TreeNode *node = getTarget(target, curr->left);
            if (node != NULL)
                return node;
            node = getTarget(target, curr->right);
            if (node != NULL)
                return node;
        }
        return NULL;
    }

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        return getTarget(target, cloned);
    }
};