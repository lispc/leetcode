/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int p2(int n){
        if(n==0){
            return 1;
        }
        int h = n/2;
        int hp = p2(h);
        return hp*hp*(n%2==1?2:1);
    }
    TreeNode* rec(ListNode*head,int n,ListNode*&tail){//n num
        if(n==0){
            tail = head;
            return NULL;
        }
        if(n==1){
            auto res = new TreeNode(head->val);
            tail = head->next;
            return res;
        }
        ListNode* p;
        ListNode* pp;
        auto l = rec(head,n/2,p);
        auto res = new TreeNode(p->val);
        auto r = rec(p->next,n-n/2-1,pp);
        res->left = l;
        res->right = r;
        tail = pp;
        return res;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head){
            return NULL;
        }
        int ll = 0;
        auto cur = head;
        while(cur){
            cur=cur->next;
            ll++;
        }
        if(ll==1){
            return new TreeNode(head->val);
        }
        int left_len = ll/2;
        ListNode* lp;
        auto l = rec(head,left_len,lp);
        auto res = new TreeNode(lp->val);
        auto r = sortedListToBST(lp->next);
        res->left = l;
        res->right = r;
        return res;
        
        
    }
};