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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head){
            return NULL;
        }
        if(m==n){
            return head;
        }
        ListNode N(0);
        N.next = head;
        int cnt = 0;
        auto cur = &N;
        while(cur){
            if(cnt+1==m){
                break;
            }
            cnt++;
            cur=cur->next;
        }
        auto back = cur;
        auto back_next = cur->next;//constant
        cnt++;
        cur=cur->next;
        auto src = cur;
        cur=cur->next;
        cnt++;
        while(cur){
            if(cnt==n+1){
                break;
            }
            auto p =cur->next;
            cur->next = src;
            src = cur;
            cur = p;
            cnt++;
        }
        back_next->next = cur;
        back->next = src;
        return N.next;
        
    }
};