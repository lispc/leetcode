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
    bool rec(TreeNode* p,int&h){
        if(!p){
            h = 0;
            return true;
        }
        int rh,lh;
        if(rec(p->left,lh)&&rec(p->right,rh)){
            auto b = -1<=rh-lh&&rh-lh<=1;
            if(b){
                h = max(lh,rh)+1;
                return true;
            }
        }
        return false;
    }
    bool isBalanced(TreeNode *root) {
        int s;
        return rec(root,s);
    }
};