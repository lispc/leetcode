class Solution {
public:
    void sp(int*p1,int*p2){
        int t = *p1;
        *p1=*p2;
        *p2=t;
    }
    void sortColors(int A[], int n) {
        if(!n){
            return;
        }
        int p0 = 0;
        int p2 = n-1;
        for(int i=0;i<n;){
            int v = A[i];
            if(v==0){
                if(p0==i){
                    i++;
                    continue;
                }
                sp(A+p0,A+i);
                p0++;
            }else if(v==2){
                if(p2<=i){
                    break;
                }
                sp(A+p2,A+i);
                p2--;
            }else{
                i++;
            }
        }
    }
};