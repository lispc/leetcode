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
    TreeNode *sortedArrayToBST(vector<int> &num) {
       int l = num.size();
       if(l==0){
           return NULL;
       }
       if(l==1){
           return new TreeNode(num[0]);
       }
       int mid = l/2;
       auto res = new TreeNode(num[mid]);
       auto ld = vector<int>(num.begin(),num.begin()+mid);
       res->left = sortedArrayToBST(ld);
       auto rd = vector<int>(num.begin()+mid+1,num.end());
       res->right = sortedArrayToBST(rd);
       return res;
    }
};