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
    bool hasCycle(ListNode *head) {
        auto p2 = head;
        auto p1 = head;
        while(p2){
            if(!p2->next){
                return false;
            }
            p2 = p2->next->next;
            p1 = p1->next;
            if(p1==p2){
                return true;
            }
        }
        return false;
    }
};