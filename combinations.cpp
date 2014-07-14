class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> res;
        if(k>n)
            return res;
        if(k==n)
        {
            vector<int> iv(k);
            iota(iv.begin(),iv.end(),1);
            res.push_back(iv);
            return res;
        }
        if(k==0)
        {
            //vector<int> iv;
            res.push_back(vector<int>());
            return res;
        }
        auto t = combine(n-1,k);
        res.insert(res.end(),t.begin(),t.end());
        auto r = combine(n-1,k-1);
        for(auto & rr:r)
        {
            rr.push_back(n);
        }
        res.insert(res.end(),r.begin(),r.end());
        return res;
        
    }
};