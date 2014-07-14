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
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head){
            return NULL;
        }
        ListNode* cnter = head;
        int l = 0;
        while(cnter){
            l++;
            cnter=cnter->next;
        }
        if(l<=k){
            k=k%l;
        }
        if(k==0){
            return head;
        }
        ListNode* cur = head;
        ListNode* back = head;
        int cnt = 0;
        while(cur&&cnt<k){
            cnt++;
            cur=cur->next;
        }
        while(cur&&cur->next){
            cur=cur->next;
            back=back->next;
        }
        ListNode* newhead = back->next;
        cur->next=head;
        back->next=NULL;
        return newhead;
    }
};