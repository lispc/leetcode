class Solution {
public:
    map<string,vector<vector<string>>> cache;
    bool p(string s){
        return s==string(s.rbegin(),s.rend());
    }
    /*
    vector<vector<string>> cache_p(string s){
        if(cache.find(s)==cache.end()){
            auto res = 
        }
    }*/
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        int l = s.size();
        if(l==1){
            vector<string> vs;
            vs.push_back(s);
            res.push_back(vs);
            return res;
        }
        if(cache.find(s)!=cache.end()){
            return cache[s];
        }
        for(int i=1;i<l;i++){
            string seg = s.substr(0,i);
            if(!p(seg)){
                continue;
            }
            auto rest = partition(s.substr(i));
            for(int j=0;j<rest.size();j++){
                vector<string> item;
                item.push_back(seg);
                item.insert(item.end(),rest[j].begin(),rest[j].end());
                res.push_back(item);
            }
        }
        if(p(s)){
            vector<string> vs;
            vs.push_back(s);
            res.push_back(vs);
        }
        cache[s]=res;
        return res;
    }
};