/**
 * 
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
    TreeNode* p1;
    TreeNode* p2;
    TreeNode* pre;
    void rec(TreeNode* p){
        if(!p){
            return;
        }
        rec(p->left);
        if(pre)
        if(p->val<pre->val){
            if(!p1){
                p1 = pre;
            }
            p2 = p;
        }
        pre = p;
        rec(p->right);
    }
    void recoverTree(TreeNode *root) {
        p1 = NULL;
        pre = NULL;
        rec(root);
        int t = p1->val;
        p1->val = p2->val;
        p2->val = t;
    }
};