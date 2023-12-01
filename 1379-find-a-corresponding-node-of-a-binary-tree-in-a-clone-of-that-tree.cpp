#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *getTarget(TreeNode *target, TreeNode *curr)
{
    TreeNode *answer;
    if (curr == NULL)
        return NULL;
    if (target->val == curr->val)
    {
        answer = curr;
    }
    else
    {
        TreeNode *node = getTarget(target, curr->left);
        if (node != NULL)
            answer = node;
        node = getTarget(target, curr->right);
        if (node != NULL)
            answer = node;
    }
    return answer;
}

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
    return getTarget(target, cloned);
}

int main()
{
    return 0;
}