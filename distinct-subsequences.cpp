class Solution {
public:
    int res = 0;
    map<pair<int,int>,int> cache;
    const char* stail;
    const char* ttail;
    const char* gps;
    const char* gpt;
    int ls;
    int lt;
    int rec(int sl,int tl){
        if(cache.find(make_pair(sl,tl))!=cache.end()){
            return cache[make_pair(sl,tl)];
        }
        auto ps = stail - sl;
        auto pt = ttail - tl;
        if(sl<tl){
            return 0;
        }
        if(tl==0){
            return 1;
        }
        char c = *pt;
        int i = 0;
        auto final = 0;
        while(i<=sl-tl){
            if(ps[i]==c){
                final += rec(sl-i-1,tl-1);
            }
            i++;
        }
        cache[make_pair(sl,tl)]=final;
        return final;
    }
    int numDistinct(string S, string T) {
        ls = S.size();
        lt = T.size();
        if(!ls||!lt){
            return 0;
        }
        stail = S.c_str()+ls;
        ttail = T.c_str()+lt;
        gps = S.c_str();
        gpt = T.c_str();
        auto res = rec(ls,lt);
        return res;
    }
};