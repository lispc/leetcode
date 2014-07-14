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
    ListNode* merge(ListNode*l1,ListNode*l2){
        if(!l2){
            return l1;
        }
        if(!l1){
            return l2;
        }
        ListNode n(0);
        auto pn = &n;
        auto last = pn;
        while(l1&&l2){
            int v1 = l1->val;
            int v2 = l2->val;
            if(v1<=v2){
                last->next = l1;
                last = last->next;
                l1 = l1->next;
            }else{
                last->next = l2;
                l2 = l2->next;
                last = last->next;
            }
        }
        if(l1){
            last->next = l1;
        }
        if(l2){
            last->next = l2;
        }
        return pn->next;
    }
    ListNode *sortList(ListNode *head) {
        if(!head){
            return NULL;
        }
        if(!head->next){
            return head;
        }
        auto last = head;
        auto half = head;
        ListNode n(0);
        auto pn = &n;
        pn->next = head;
        while(last){
            if(!last->next){
                break;
            }
            pn = pn->next;
            last = last->next->next;
            half = half->next;
        }
        pn->next = NULL;
        auto l = sortList(head);
        auto r = sortList(half);
        return merge(l,r);
        
    }
};