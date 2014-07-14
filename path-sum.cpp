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
    bool rec(TreeNode* root,int sum){
        int v = root->val;
        auto l = root->left;
        auto r = root->right;
        if(l&&r){
            return rec(root->left,sum-v)||rec(root->right,sum-v);     
        }
        if(!l&&!r){
            return v == sum;
        }
        if(l){
            return rec(l,sum-v);
        }
        if(r){
            return rec(r,sum-v);
        }
    }
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root){
            return false;
        }
        return rec(root,sum);
    }
};