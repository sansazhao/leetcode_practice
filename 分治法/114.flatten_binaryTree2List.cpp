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
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *right = root->right;
        root->right = root->left;
        root->left = nullptr;
        flatten(root->right);
        while (root->right)
            root = root->right;
        flatten(right);
        root->right = right;
    }
};