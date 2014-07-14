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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int c=n;
        ListNode* tp=head;
        ListNode* opt=head;
        while(c)
        {
            tp=tp->next;
            c--;
        }
        if(!tp)
            return head->next;
        while(tp->next)
        {
            tp=tp->next;
            opt=opt->next;
        }
        opt->next=opt->next->next;
        return head;
        
    }
};