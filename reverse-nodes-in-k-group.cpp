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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k<=1){
            return head;
        }
        auto each_head = head;
        ListNode n(0);
        auto pn = &n;
        pn->next = head;
        auto last_head = pn;
        while(1){
            int c = k-1;
            auto pb = each_head;
            ListNode* next_head;
            int break_f = 0;
            while(c){
                if(!pb){
                    break_f = 1;
                    last_head->next = each_head;
                    break;
                }else{
                    pb = pb->next;
                    c--;
                }
            }
            if(!pb){
                last_head->next = each_head;
                break_f = 1;
            }else{
                next_head = pb->next;
            }
            if(break_f){
                break;
            }
            auto cur = each_head;
            auto cur_child = each_head->next;
            while(cur_child!=next_head){
                auto tt = cur_child->next;
                cur_child->next = cur;
                cur = cur_child;
                cur_child = tt;
            }
            //each_head->next = next_head;
            last_head->next = cur;
            last_head = each_head;
            each_head->next = NULL;
            each_head = next_head;
            
        }
        return pn->next;
    }
};