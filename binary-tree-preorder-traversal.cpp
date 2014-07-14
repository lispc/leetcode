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
    //vector<int> ivec;
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ivec;
        if(root){
            ivec.push_back(root->val);
            if(root->left)
            {
                auto left = preorderTraversal(root->left);
                ivec.insert(ivec.end(),left.begin(),left.end());
            }
            if(root->right)
            {
                auto right = preorderTraversal(root->right);
                ivec.insert(ivec.end(),right.begin(),right.end());
            }
        }
        return ivec;
    }
    
};