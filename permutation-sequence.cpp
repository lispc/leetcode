class Solution {
public:
    int f[10];
    int d[9];
    vector<int> rec(int n,int k){//0 start
        if(n==1){
            return vector<int>(1,1);
        }
        vector<int> res;
        int ff = f[n-1];
        int st = k/ff+1;
        res.push_back(st);
        vector<int> vd(d,d+9);
        vd.erase(vd.begin()+st-1);
        auto rr = rec(n-1,k%ff);
        for(auto i:rr){
            res.push_back(vd[i-1]);
        }
        return res;
        
    }
    string getPermutation(int n, int k) {
        if(n==1){
            return "1";
        }
        f[0]=1;
        for(int i=1;i<=9;i++){
            f[i]=f[i-1]*i;
            d[i-1]=i;
        }
        string s;
        for(auto i:rec(n,k-1)){
            s.append(1,'0'+i);
        }
        return s;
        
        
        
    }
};