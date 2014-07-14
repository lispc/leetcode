/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(!root){
            return 0;
        }
        /*
        if(!root->left){
            return 1+maxDepth(root->right);
        }
        if(!root->right){
            return 1+maxDepth(root->left);
        }
        */
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};