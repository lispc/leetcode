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
    bool isValidBST(TreeNode *root) {
        return rec(root,numeric_limits<int>::min(),numeric_limits<int>::max());
    }
    bool rec(TreeNode* root, int l,int r)
    {
        if(!root)
            return true;
        int v=root->val;
        if(v<=l)
            return false;
        if(v>=r)
            return false;
        return rec(root->left,l,v)&&rec(root->right,v,r);
    }
};