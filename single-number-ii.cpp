class Solution {
public:
    int singleNumber(int A[], int n) {
        int size = sizeof(int)*8;
        vector<int> cnt(size,0);
        int res = 0;
        for(int i=0;i<size;i++){
            for(int j=0;j<n;j++){
                cnt[i]+=(A[j]>>i)&1;
            }
            res|=((cnt[i]%3)<<i);
        }
        return res;
    }
};