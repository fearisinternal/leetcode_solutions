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
    bool Balance = true;
    int getLevel(TreeNode* root){
        if (root == NULL){
            return 0;
        }
        int l = getLevel(root->left);
        int r = getLevel(root->right);
        if (abs(l-r)>1) Balance = false; 
        return max(l, r)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        getLevel(root);
        return Balance;
    }
};