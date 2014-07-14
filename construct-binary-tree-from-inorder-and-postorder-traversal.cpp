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
    TreeNode *rec(vector<int>::iterator ist,vector<int>::iterator ied,vector<int>::iterator pst, vector<int>::iterator ped){
        int size = ped-pst;
        if(!size){
            return NULL;
        }
        auto n = new TreeNode(*(ped-1));
        auto left_size = find(ist,ied,*(ped-1))-ist;
        n->left = rec(ist,ist+left_size,pst,pst+left_size);
        n->right = rec(ist+left_size+1,ied,pst+left_size,ped-1);
        return n;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return rec(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
};