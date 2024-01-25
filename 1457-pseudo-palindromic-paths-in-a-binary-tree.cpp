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
    int pseudoPalindromicPaths(TreeNode *root)
    {
        std::vector<std::pair<TreeNode *, bitset<10>>> s;
        s.push_back({root, 0});
        int ans = 0;
        while (!s.empty())
        {
            auto [node, p] = s.back();
            s.pop_back();
            p.flip(node->val);
            if (!node->left && !node->right)
            {
                if (p.count() <= 1)
                    ans++;
                continue;
            }
            else
            {
                if (node->left)
                    s.push_back({node->left, p});
                if (node->right)
                    s.push_back({node->right, p});
            }
        }
        return ans;
    }
};