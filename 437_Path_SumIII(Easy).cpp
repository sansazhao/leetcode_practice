/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二叉树 递归
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        return path(root, sum)+pathSum(root->left, sum)+pathSum(root->right, sum); 
    }
    
    int path(TreeNode* root, int sum){
        if(!root)return 0;
        int ret = 0;
        if(root->val == sum){
            ret++;
        }
        ret += path(root->left,sum-root->val) + path(root->right,sum-root->val);
        return ret;
    }
};