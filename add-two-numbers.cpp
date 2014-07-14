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
    ListNode* rec(ListNode* p1,ListNode* p2,bool c){
         if(!p1){
             if(p2){
                return rec(p2,p1,c);
             }else{
                 if(c){
                    return new ListNode(1);
                 }else{
                     return NULL;
                 }
             }
        }
        if(!p2){
            int v = p1->val;
            int nv = v+int(c);
            if(nv<10){
                auto res = new ListNode(nv);
                res->next = rec(p1->next,p2,false);
                return res;
            }else{
                int r = nv%10;
                auto res = new ListNode(r);
                res->next = rec(p1->next,p2,true);
                return res;
            }
        }
        int v = p1->val+p2->val+int(c);
        if(v<10){
            auto res = new ListNode(v);
            res->next = rec(p1->next,p2->next,false);
            return res;
        }else{
            auto res = new ListNode(v%10);
            res->next = rec(p1->next,p2->next,true);
            return res;
        }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
       return rec(l1,l2,false);
    }
};