class Solution {
public:
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        int l = s.size();
        if(l==0){
            return true;
        }
        if(l==1){
            return dict.find(s)!=dict.end();
        }
        vector<bool> ok(l+1,false);
        ok[0]=true;
        ok[1]=dict.find(s.substr(0,1))!=dict.end();
        for(int i=2;i<=l;i++){
            for(int j=0;j<i;j++){
                string seg = s.substr(j,i-j);
                if(ok[j]&&dict.find(seg)!=dict.end()){
                    ok[i]=true;
                    break;
                }
            }
        }
        return ok[l];
    }
};