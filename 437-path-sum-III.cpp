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
int ans=0;

void findSum(TreeNode* root, int target, int64_t sum, unordered_map<int64_t, int64_t>& map) {
    sum+=root->val;
    ans+= map[sum-target];
    map[sum]++;
    if (root->left) findSum(root->left, target, sum, map);
    if (root->right) findSum(root->right, target, sum, map);
    map[sum]--;
}
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int64_t, int64_t> map;
        map[0] = 1;
        if (!root) return ans;
        findSum(root, targetSum, 0, map);
    return ans;
    }
};