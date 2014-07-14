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
    vector<vector<int>> res;
    vector<int> pathv;
    void rec(TreeNode* root,int sum){
        int v = root->val;
        auto l = root->left;
        auto r = root->right;
        pathv.push_back(v);
        if(l&&r){
            rec(l,sum-v);
            rec(r,sum-v);
        }
        else if(!l&&!r){
            if(v == sum){
                res.push_back(pathv);        
            }
        }
        else if(l){
            rec(l,sum-v);
        }
        else if(r){
           rec(r,sum-v);
        }
        pathv.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(!root){
            return res;
        }
        rec(root,sum);
        return res;
        
    }
};