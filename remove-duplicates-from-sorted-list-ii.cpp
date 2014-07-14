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
        ListNode n(0);
        auto last = &n;
        auto candi = head;
        int cv = head->val;
        auto cur = head->next;
        while(cur){
            int v = cur->val;
            if(v==cv){
                while(cur){
                    if(cur->val==cv){
                        cur=cur->next;
                    }else{
                        break;
                    }
                }
                if(!cur){
                    last->next=NULL;
                    return n.next;
                }else{
                    candi = cur;
                    cv = candi->val;
                    cur = cur->next;
                }
            }else{
                last->next = candi;
                last = last->next;
                candi = cur;
                cv = candi->val;
                cur = cur->next;
            }
        }
        last->next = candi;
        return n.next;
    }
};