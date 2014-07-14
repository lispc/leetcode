class Solution {
public:
    void rec(vector<vector<int>>& res,map<int,int>& fr,vector<int>& path,int forbid){
        int empty = 1;
        for(auto it=fr.begin();it!=fr.end();it++){
            int v = it->first;
            int f = it->second;
            if(f){
                empty = 0;
            }
            if(path.size()&&v==forbid){
                continue;
            }
            if(f){
                empty = 0;
                for(int j=1;j<=f;j++){
                    fr[v]-=j;
                    path.insert(path.end(),j,v);
                    rec(res,fr,path,v);
                    fr[v]+=j;
                    path.erase(path.end()-j,path.end());
                }
            }
        }
        if(empty){
            res.push_back(path);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> res;
        map<int,int> fr;
        int numsize = num.size();
        for(int i=0;i<numsize;i++){
            int v = num[i];
            if(fr.find(v)!=fr.end()){
                fr[v]++;
            }else{
                fr[v]=1;
            }
        }
        vector<int> path;
        rec(res,fr,path,0);
        return res;
        
    }
};