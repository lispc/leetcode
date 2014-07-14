class Solution {
public:
    void rec(vector<int> pre, vector<int> suf,vector<vector<int>>& result){
        if(suf.size()==0){
            result.push_back(pre);
            return;
        }
        vector<int> new_suf(suf.begin()+1,suf.end());
        int v = suf[0];
        rec(pre,new_suf,result);
        pre.push_back(v);
        rec(pre,new_suf,result);
    }
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<int> seed;
        vector<vector<int>> res;
        rec(seed,S,res);
        return res;
    }
};