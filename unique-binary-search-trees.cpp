class Solution {
public:
    int numTrees(int n) {
        if(!n){
            return 1;
        }
        vector<int> buf(n+1,0);
        buf[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                buf[i]+=buf[j]*buf[i-1-j];
            }
        }
        return buf[n];
    }
};