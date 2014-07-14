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
    TreeNode *rec(vector<int>::iterator pst,vector<int>::iterator ped,vector<int>::iterator ist, vector<int>::iterator ied){
        int size = ped-pst;
        if(!size){
            return NULL;
        }
        auto n = new TreeNode(*pst);
        auto left_size = find(ist,ied,*pst)-ist;
        n->left = rec(pst+1,pst+1+left_size,ist,ist+left_size);
        n->right = rec(pst+1+left_size,ped,ist+left_size+1,ied);
        return n;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return rec(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
};