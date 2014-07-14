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
    void flatten(TreeNode *root) {
        if(root)
        rec(root,NULL);
    }
    void rec(TreeNode* n,TreeNode* next)
    {
        if(n->right==NULL)
            n->right=next;
        else 
            rec(n->right,next);
        if(n->left)
        {
            rec(n->left,n->right);
            //test(n->left,n->right);
            n->right=n->left;
            n->left=NULL;
        }
        //return n;
    }
    void test(TreeNode*a,TreeNode*b)
    {
        while(a!=b)
        {
            a=a->right;
        }
    }
    /*TreeNode* next(TreeNode* c)
    {
        if(c->right)
        return next(c->right);
        if(c->left)
        return 
    }
    */
};