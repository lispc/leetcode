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
    ListNode* rev(ListNode*head){
        if(!head){
            return NULL;
        }
        if(!head->next){
            return head;
        }
        auto pre = head->next;
        head->next = NULL;
        auto past = head;
        while(pre){
            auto new_pre = pre->next;
            pre->next = past;
            past = pre;
            pre = new_pre;
        }
        return past;
    }
    void reorderList(ListNode *head) {
        if(!head){
            return;
        }
        if(!head->next){
            return;
        }
        if(!head->next->next){
            return;
        }
        auto tail = head;
        auto half = head;
        while(tail){
            if(!tail->next){
                break;
            }
            half = half->next;
            tail = tail->next->next;
        }
        auto back_head = half->next;
        half->next = NULL;
        auto revl = rev(back_head);
        auto it = head;
        while(revl){
            auto new_revl = revl->next;
            auto new_it = it->next;
            revl->next = it->next;
            it->next = revl;
            it = new_it;
            revl = new_revl;
        }
        //return head;
    }
};