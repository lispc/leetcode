class Solution {
public:
    map<pair<int,int>,bool> cache;
    string gss;
    int gls;
    string gsp;
    int glp;
    bool m(int s_st,int p_st){
        auto key = make_pair(s_st,p_st);
        if(cache.find(key)!=cache.end()){
            return cache[key];
        }
        int ls = gls-s_st;
        int lp = glp-p_st;
        if(!lp){
            auto res = ls==0;
            cache[key] = res;
            return res;
        }
        if(!ls){
            bool res;
            if(lp==1){
                res = false;
            }else if(gsp[p_st+1]=='*'){
                res = m(gls,p_st+2);
            }else{
                res = false;
            }
            cache[key]=res;
            return res;
        }
        char pc = gsp[p_st];
        if(lp==1){
            bool res;
            if(pc=='.'){
                res = ls==1;
            }else{
                res = gss[s_st]==pc&&ls==1;
            }
            cache[key] = res;
            return res;
        }
        if(gsp[p_st+1]!='*'){
            bool res;
            if(pc=='.'){
                res = m(s_st+1,p_st+1);
            }else{
                res = gss[s_st]==pc&&m(s_st+1,p_st+1);
            }
            cache[key] = res;
            return res;
        }
        if(pc=='.'){
            bool res = false;
            for(int i=ls;i>=0;i--){
                if(m(s_st+i,p_st+2)){
                    res = true;
                    break;
                }
            }
            cache[key] = res;
            return res;
        }else{
            int os = 0;
            while(gss[s_st+os]==pc){
                os++;
            }
            bool res = false;
            for(int i=os;i>=0;i--){
                if(m(i+s_st,p_st+2)){
                    res = true;
                    break;
                }
            }
            cache[key] = res;
            return res;
            
        }
        
    }
    bool isMatch(const char *s, const char *p) {
        gss = s;
        gsp = p;
        gls = gss.size();
        glp = gsp.size();
        return m(0,0);
        
    }
};