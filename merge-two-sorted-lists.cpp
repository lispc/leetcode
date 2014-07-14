/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void rec(ListNode*l1,ListNode*l2,ListNode*p){
        if(l1==NULL){
            p->next=l2;
            return;
        }
        if(l2==NULL){
            p->next=l1;
            return;
        }
        int v1 = l1->val;
        int v2 = l2->val;
        if(v1<v2){
            p->next=l1;
            rec(l1->next,l2,l1);
        }else{
            p->next=l2;
            rec(l1,l2->next,l2);
        }
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode tmp(0);
        rec(l1,l2,&tmp);
        return tmp.next;
        
        
    }
};