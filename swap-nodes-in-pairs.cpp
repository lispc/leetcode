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
    ListNode *swapPairs(ListNode *head) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        //ListNode* leg = head;
        ListNode* fu  = head->next->next;
        ListNode* res = head->next;
        head->next->next=head;
        head->next=swapPairs(fu);
        return res;
    }
};