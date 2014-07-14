/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*,RandomListNode*> buf;
        if(!head){
            return NULL;
        }
        auto cur = head;
        RandomListNode n(0);
        auto pn = &n;
        auto last = pn;
        while(cur){
            int v = cur->label;
            auto p = new RandomListNode(v);
            last->next = p;
            last = p;
            buf[cur]=p;
            cur = cur->next;
        }
        cur = head;
        auto iter = pn->next;
        while(cur){
            if(cur->random){
                iter->random = buf[cur->random];
            }
            iter = iter->next;
            cur = cur->next;
        }
        return pn->next;
    }
};