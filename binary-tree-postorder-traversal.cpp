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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<tuple<TreeNode*,int>> sk;
        vector<int> res;
        if(!root){
            return res;
        }
        sk.push(make_tuple(root,0));
        while(!sk.empty()){
            auto n = get<0>(sk.top());
            auto vis = get<1>(sk.top());
            sk.pop();
            if(vis){
                res.push_back(n->val);
            }else{
                sk.push(make_tuple(n,1));
                if(n->right){
                    sk.push(make_tuple(n->right,0));
                }
                if(n->left){
                    sk.push(make_tuple(n->left,0));
                }
            }
        }
        return res;
    }
};