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
    int rec(TreeNode* root,int c){
        if(!root){
            return 0;
        }
        if(!root->right&&!root->left){
            return 10*c+root->val;
        }
        //if(root->right&&root->left){
            return rec(root->right,10*c+root->val)+rec(root->left,10*c+root->val);
        //}
        //return  rec(root->right,10*c+root->val)
    }
    int sumNumbers(TreeNode *root) {
        return rec(root,0);
    }
};