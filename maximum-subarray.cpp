class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return A[0];
        }
        int mid = n/2;
        int l = maxSubArray(A,mid);
        int r = maxSubArray(A+mid,n-mid);
        int ml = 0;
        int sl = 0;
        int li = mid-1;
        while(li>=0){
            sl+=A[li];
            if(sl>ml){
                ml=sl;
            }
            li--;
        }
        int mr = A[mid];
        int sr = A[mid];
        int ri = mid+1;
        while(ri<n){
            sr+=A[ri];
            if(sr>mr){
                mr=sr;
            }
            ri++;
        }
        return max(mr+ml,max(l,r));
        
    }
};