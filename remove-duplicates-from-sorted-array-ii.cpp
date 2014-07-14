class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!n){
            return 0;
        }
        int state = 1;
        int cur = 1;
        int last = A[0];
        for(int i=1;i<n;i++){
            int v = A[i];
            if(v!=last){
                state = 1;
                A[cur++] = v;
                last = v;
                continue;
            }
            if(state==1){
                state = 2;
                A[cur++] = v;
                continue;
            }
        }
        return cur;
    }
};