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
     //bool hasCycle(ListNode *head) {
        
    //}
    ListNode *detectCycle(ListNode *head) {
        auto p2 = head;
        auto p1 = head;
        ListNode* pp = NULL;
        while(p2){
            if(!p2->next){
                return NULL;
            }
            p2 = p2->next->next;
            p1 = p1->next;
            if(p1==p2){
                pp = p1;
                break;
            }
        }
        if(!pp){
            return false;
        }
        auto ppp = head;
        while(ppp!=pp){
            ppp = ppp ->next;
            pp = pp->next;
        }
        return pp;
    }
};