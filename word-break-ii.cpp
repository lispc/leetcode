class Solution {
public:
    unordered_set<string> gdict;
    map<int,vector<vector<string>>> cache;
    string gs;
    int gl;
    vector<vector<string>>& rec(int loc){
        if(cache.find(loc)!=cache.end()){
            return cache[loc];
        }
        vector<vector<string>> local_res;
        if(loc==gl){
            local_res.push_back(vector<string>());
        }else{
            for(int i=loc+1;i<=gl;i++){
                string seg = gs.substr(loc,i-loc);
                bool b = gdict.find(seg)!=gdict.end();
                if(b){
                    for(auto item:rec(i)){
                        vector<string> tp = item;
                        tp.push_back(seg);
                        local_res.push_back(tp);
                    }
                }
            }
        }
        cache[loc]=local_res;
        return cache[loc];
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        gdict = dict;
        gs = s;
        gl = s.size();
        vector<string> path;
        auto res = rec(0);
        vector<string> final_res;
        for(auto item:res){
            string tp;
            for(int t=item.size()-1;t>=0;t--){
                if(t!=item.size()-1){
                    tp.append(" ");
                }
                tp.append(item[t]);
            }
            final_res.push_back(tp);
        }
        return final_res;
    }
};