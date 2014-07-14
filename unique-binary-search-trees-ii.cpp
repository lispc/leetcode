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
    //map<int,vector<TreeNode*>> cache;
    vector<TreeNode *> rec(int n,int seed){
        vector<TreeNode*> res;
        if(n==0){
            res.push_back(NULL);
            return res;
        }
        for(int i=0;i<=n-1;i++){
            auto l = rec(i,seed);
            auto r = rec(n-1-i,seed+1+i);
            for(auto ll:l){
                for(auto rr:r){
                    auto root = new TreeNode(seed+i);
                    root->left = ll;
                    root->right = rr;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n) {
        return rec(n,1);
    }
};