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
    struct c
    {
      //bool operator()(const ListNode*& lhs, const ListNode*& rhs)
      bool operator()(ListNode* lhs, ListNode* rhs)
      {
        return lhs->val>rhs->val;
      }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size()==0)
            return NULL;
        priority_queue<ListNode*,vector<ListNode*>,c> pq;
        for(auto b=begin(lists);b!=end(lists);b++)
        {
            if(*b)
                pq.push(*b);
        }
        if(pq.empty())
            return NULL;
        ListNode ll(-7);
        ListNode* i = &ll;
        //auto res = pq.top();
        //auto i = res;
        //pq.pop();
        while(!pq.empty())
        {
            auto t=pq.top();
            pq.pop();
            if(t->next)
                pq.push(t->next);
            i->next=t;
            i=t;            
        }
        return ll.next;
    }
};