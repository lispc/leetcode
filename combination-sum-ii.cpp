class Solution {
public:
    void rec(vector<int>::iterator st,vector<int>::iterator ed,int target,vector<vector<int>>&res){
        if(st==ed){
            return;
        }
        if(st+1==ed){
            if(*st==target){
                res.push_back(vector<int>(1,target));
            }
            return;
        }
        if(target<*st){
            return;
        }
        if(target==*st){
            res.push_back(vector<int>(1,target));
            return;
        }
        vector<vector<int>> ires;
        rec(st+1,ed,target-*st,ires);
        for(auto item:ires){
            vector<int> pre(1,*st);
            pre.insert(pre.end(),item.begin(),item.end());
            res.push_back(pre);
        }
        ires.clear();
        rec(st+1,ed,target,ires);
        for(auto item:ires){
            res.push_back(item);
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        sort(num.begin(),num.end());
        rec(num.begin(),num.end(),target,res);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
        
    }
};