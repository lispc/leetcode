class Solution {
public:
    void rec(vector<int>::iterator st,vector<int>::iterator ed,vector<vector<int>>& res){
        if(st+1==ed){
            res.push_back(vector<int>(st,ed));
            return;
        }
        int v = *st;
        vector<vector<int>> ires;
        rec(st+1,ed,ires);
        for(int i=0;i<ed-st;i++){
            for(auto item:ires){
                vector<int> cp = item;
                cp.insert(cp.begin()+i,v);
                res.push_back(cp);
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        if(num.size()==0){
            return res;
        }
        rec(num.begin(),num.end(),res);
        return res;
    }
};