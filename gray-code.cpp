class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n==0){
            return vector<int>(1,0);
        }
        if(n==1){
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        auto rr = grayCode(n-1);
        int size = rr.size();
        for(int i=0;i<size;i++){
            res.push_back(rr[i]);
        }
        for(int i=0;i<size;i++){
            res.push_back(rr[size-1-i]+size);
        }
        return res;
    }
};