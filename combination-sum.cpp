class Solution {
public:
    void rec(vector<int>::iterator st,vector<int>::iterator ed,int t,vector<int>& path,vector<vector<int>>& res){
        if(t==0){
            res.push_back(path);
            return;
        }
        if(st==ed){
            return;
        }
        int i=0;
        for(;i**st<=t;i++){
            rec(st+1,ed,t-i**st,path,res);
            path.push_back(*st);
        }
        while(i){
            path.pop_back();
            i--;
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int l = candidates.size();
        vector<vector<int>> res;
        vector<int> seed;
        rec(candidates.begin(),candidates.end(),target,seed,res);
        return res;
        
    }
};