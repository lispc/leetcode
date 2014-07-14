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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> ivv;
        if(!root)
            return ivv;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while(!q1.empty())
        {
            vector<int> iv;
            while(!q1.empty())
            {
                TreeNode* n = q1.front();
                q1.pop();
                iv.push_back(n->val);
                if(n->left)
                q2.push(n->left);
                if(n->right)
                q2.push(n->right);
            }
            ivv.push_back(iv);
            q1.swap(q2);
            
        }
        return ivv;
        
    }
};