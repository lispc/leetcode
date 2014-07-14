class Solution {
public:
    vector<vector<int>> rec(string s,int n){
        vector<vector<int>> res;
        if(s==""){
            return res;
        }
        if(n==1){
            if(s[0]=='0'&&s.size()>1){
                return res;
            }
            int v = atoi(s.c_str());
            if(v<=255){
                res.push_back(vector<int>(1,v));
                return res;
            }
        }
        int l = s.size();
        for(int i=1;i<=min(l,3);i++){
            string seg = s.substr(0,i);
            if(seg[0]=='0'&&seg.size()>1){
                continue;
            }
            int v = atoi(seg.c_str());
            if(v<=255){
                auto rr = rec(s.substr(i),n-1);
                for(auto item:rr){
                    vector<int> tmp(1,v);
                    tmp.insert(tmp.end(),item.begin(),item.end());
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
    vector<string> restoreIpAddresses(string s) {
        int ll = s.size();
        vector<string> r;
        if(ll>12||ll<4){
            return r;
        }
        auto res = rec(s,4);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        for(auto vi:res){
            stringstream ss;
            for(int i=0;i<vi.size();i++){
                if(i!=0){
                    ss<<".";
                }
                ss<<vi[i];
            }
            r.push_back(ss.str());
        }
        return r;
        
    }
};