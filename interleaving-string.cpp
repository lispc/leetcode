class Solution {
public:
    string gs1;
    string gs2;
    string gs3;
    map<pair<int,int>,bool> cache;
    bool match(int l1,int l2){
        auto p = make_pair(l1,l2);
        if(cache.find(p)!=cache.end()){
            return cache[p];
        }
        bool res = false;
        if(l1==0){
            if(gs2.substr(0,l2)==gs3.substr(0,l2)){
                res = true;
            }
        }else if(l2==0){
             if(gs1.substr(0,l1)==gs3.substr(0,l1)){
                res = true;
            }
        }else{
            char c3 = gs3[l1+l2-1];
            char c1 = gs1[l1-1];
            char c2 = gs2[l2-1];
            res=((c1==c3&&match(l1-1,l2))||(c2==c3)&&match(l1,l2-1));
        }
        cache[p]=res;
        return res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        if(l1==0){
            return s2==s3;
        }
        if(l2==0){
            return s1==s3;
        }
        if(l1+l2!=l3){
            return false;
        }
        gs1 = s1;
        gs2 = s2;
        gs3 = s3;
        return match(l1,l2);
    }
};