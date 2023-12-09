#include <string>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::string tree2str(TreeNode *root)
{
    std::string s = "";
    if (root != nullptr)
    {
        s += std::to_string(root->val);
        if (root->left != nullptr || (root->right != nullptr))
        {
            s += "(" + tree2str(root->left) + ")";
            if (root->right != nullptr)
                s += "(" + tree2str(root->right) + ")";
        }
    }
    return s;
}

int main()
{
    return 0;
}