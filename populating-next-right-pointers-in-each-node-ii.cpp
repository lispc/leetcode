/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void rec(TreeLinkNode*p){
        if(!p){
            return;
        }
        auto l = p->left;
        auto r = p->right;
        //if(l&&r){
            rec(l);
            rec(r);
            auto ll = l;
            auto rr = r;
            while(ll&&rr){
                auto ltp = ll->next;
                TreeLinkNode* rtp = NULL;
                ll->next = rr;
                while(rr->next){
                    if(rr->left){
                        rtp = rr->left;
                        break;
                    }
                    if(rr->right){
                        rtp = rr->right;
                        break;
                    }
                    rr = rr->next;
                }
                if(rtp){
                    ll = ltp;
                    rr = rtp;
                }else{
                    rr->next = ltp;
                    break;
                }
            }
            p->next = r?r:l;
            return;
        //}
    }
    void connect(TreeLinkNode *root) {
        if(!root){
            return;
        }
        rec(root);
        while(root){
            auto tp = root->next;
            root->next = NULL;
            root = tp;
        }
    }
};