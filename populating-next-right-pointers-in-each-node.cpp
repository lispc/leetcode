/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root){
            return;
        }
        connect(root->left);
        connect(root->right);
        auto lp = root->left;
        auto rp = root->right;
        while(lp){
            lp->next=rp;
            lp=lp->right;
            rp=rp->left;
        }
        
    }
};