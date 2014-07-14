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
    pair<int,int> rec(TreeNode* root)
    {
         if(!root)
            return make_pair(0,0);
        auto l = rec(root->left);//first single second double 
        auto r = rec(root->right);
        int td = l.first+r.first+root->val;  //rec(root->left)+rec(root->right)+root->val;
        int maxd = m(td,root->left?l.second:td,root->right?r.second:td);
        //return t>m?t:m;
       
        //int l = rec(root->left);
        //int r = rec(root->right);
        return make_pair(m(m(l.first,r.first)+root->val,0),maxd);
    }
    int m(int a,int b)
    {
        return a>b?a:b;
    }
    int m(int a,int b,int c)
    {
        return m(m(a,b),c);
    }
    int maxPathSum(TreeNode *root) {
        if(!root)
            return 0;
        return rec(root).second;
       
    }
};