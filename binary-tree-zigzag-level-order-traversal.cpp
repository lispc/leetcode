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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
         vector<vector<int>> res;
         auto pv1 = new vector<TreeNode*>;
         auto pv2 = new vector<TreeNode*>;
         if(!root){
             return res;
         }
         if(!root->left&&!root->right){
             res.push_back(vector<int>(1,root->val));
             return res;
         }
         int dir = -1;
         pv1->push_back(root);
         while(!pv1->empty()){
             vector<int> buf;
             for(auto it=pv1->begin();it!=pv1->end();it++){
                 buf.push_back((*it)->val);
             }
             for(auto it=pv1->rbegin();it!=pv1->rend();it++){
                 if(dir==-1){
                     if((*it)->right){
                        pv2->push_back((*it)->right);
                     }
                     if((*it)->left){
                        pv2->push_back((*it)->left);
                     }
                 }else{
                     if((*it)->left){
                        pv2->push_back((*it)->left);
                     }
                     if((*it)->right){
                        pv2->push_back((*it)->right);
                     }
                 }
             }
             res.push_back(buf);
             dir = -dir;
             auto tp = pv1;
             pv1 = pv2;
             pv2 = tp;
             pv2->clear();
         }
         return res;
        
    }
};