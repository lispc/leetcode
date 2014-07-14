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
    ListNode *insertionSortList(ListNode *head) {
        if(!head){
            return NULL;
        }
        if(!head->next){
            return head;
        }
        ListNode n(0);
        auto pn = &n;
        pn->next = head;
        auto cur = head->next;
        head->next = NULL;
        while(cur){
            int v = cur->val;
            auto past = pn;
            int insf = 0;
            ListNode* nnext;
            while(past->next!=NULL){
                if(past->next->val>v){
                    auto res = past->next;
                    past->next = cur;
                    nnext = cur->next;
                    cur->next = res;
                    insf = 1;
                    break;
                }
                past = past->next;
            }
            if(insf){
                cur = nnext;
                continue;
            }
            past->next = cur;
            auto tp = cur->next;
            cur->next = NULL;
            cur = tp;
        }
        return pn->next;
    }
};