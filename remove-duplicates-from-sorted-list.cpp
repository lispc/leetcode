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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head){
            return NULL;
        }
        int v = head->val;
        auto cur = head->next;
        auto last = head;
        while(cur){
            int vv = cur->val;
            if(vv!=v){
                last->next = cur;
                last = cur;
                cur = cur->next;
                v = vv;
            }else{
                cur = cur->next;
            }
        }
        last->next = NULL;
        return head;
    }
};