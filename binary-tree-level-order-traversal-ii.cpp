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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        q.push(root);
        int handled = 0;
        int thislevel = 1;
        int nextlevel = 0;
        vector<int> buf;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            buf.push_back(cur->val);
            if(cur->left){
                q.push(cur->left);
                nextlevel++;
            }
            if(cur->right){
                q.push(cur->right);
                nextlevel++;
            }
            handled++;
            if(handled==thislevel){
                thislevel = nextlevel;
                nextlevel = 0;
                handled = 0;
                res.push_back(buf);
                buf.clear();
            }
        }
        return vector<vector<int>>(res.rbegin(),res.rend());
    }
};