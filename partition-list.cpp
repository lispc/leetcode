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
    ListNode *partition(ListNode *head, int x) {
        if(!head){
            return NULL;
        }
        if(!head->next){
            return head;
        }
        ListNode bn(0);
        ListNode fn(0);
        auto pbn = &bn;
        auto pfn = &fn;
        auto cur = head;
        auto last_pfn = pfn;
        auto last_pbn = pbn;
        while(cur){
            if(cur->val<x){
                last_pfn->next = cur;
                last_pfn = cur;
            }else{
                last_pbn->next = cur;
                last_pbn = cur;
            }
            cur = cur->next;
        }
        last_pbn->next = NULL;
        last_pfn->next = pbn->next;
        return pfn->next;
        
    }
};