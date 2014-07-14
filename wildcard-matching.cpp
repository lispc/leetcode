class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int sl = strlen(s);
        int pl = strlen(p);
        if(!pl){
            return !sl;
        }
        if(!sl){
            while(*p=='*'){
                p++;
            }
            return !*p;
        }
        vector<int> lastv;
        vector<int> cur;
        vector<int> swp;
        int charnum = 0;
        auto pp = p;
        while(*pp){
            if(*pp!='*'){
                charnum++;
            }
            pp++;
        }
        if(charnum>sl){
            return false;
        }
        vector<vector<int>> dp(pl,vector<int>());
        char pc = *p;
        if(pc=='?'){
            lastv.push_back(0);
        }else if(pc=='*'){
            for(int i=-1;i<sl;i++){
                lastv.push_back(i);
            }
        }else{
            if(*p==*s){
                lastv.push_back(0);
            }else{
                return false;
            }
        }
        if(pl==1){
            return lastv.back()==sl-1;
        }
        for(int i=1;i<pl;i++){
            char pc = p[i];
            if(pc=='*'){
                for(int j=lastv[0];j<sl;j++){
                    cur.push_back(j);
                }
            }else if(pc=='?'){
                for(int j:lastv){
                    if(j+1<sl){
                        cur.push_back(j+1);
                    }
                }
            }else{
                for(int j:lastv){
                    if(j+1<sl&&s[j+1]==pc){
                        cur.push_back(j+1);
                    }
                }
            }
            if(cur.empty()){
                return false;
            }
            lastv = cur;
            cur.clear();
        }
        if(lastv.back()==sl-1){
            return true;
        }
        return false;
    }
};