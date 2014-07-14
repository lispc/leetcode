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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* p = root;
        while(p){
            s.push(p);
            p=p->left;
        }
        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            res.push_back(cur->val);
            TreeNode* pp = cur->right;
            while(pp){
                s.push(pp);
                pp=pp->left;
            }
        }
        return res;
    }
};