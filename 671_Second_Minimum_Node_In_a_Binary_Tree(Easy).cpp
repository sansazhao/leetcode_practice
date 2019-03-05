/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 按照二叉树特性 递归
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        if (!root->left && !root->right) return -1;
        int leftVal = root->left->val;
        int rightVal = root->right->val;
        if (leftVal == root->val) leftVal = findSecondMinimumValue(root->left);
        if (rightVal == root->val) rightVal = findSecondMinimumValue(root->right);
        if (leftVal != -1 && rightVal != -1) return min(leftVal, rightVal);
        if (leftVal != -1) return leftVal;
        return rightVal;
    }
};