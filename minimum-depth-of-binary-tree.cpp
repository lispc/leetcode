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
    int minDepth(TreeNode *root) {
        if(!root){
            return 0;
        }
        if(!(root->right&&root->left)){
            return (minDepth(root->left)+minDepth(root->right))+1;
        }
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};