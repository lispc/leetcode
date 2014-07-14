class Solution {
public:
    int singleNumber(int A[], int n) {
        int seed = 0;
        for(int i=0;i<n;i++){
            seed = seed^A[i];
        }
        return seed;
    }
};