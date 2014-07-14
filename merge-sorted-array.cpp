class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(n==0){
            return;
        }
        if(m==0){
            for(int i=0;i<n;i++){
                A[i]=B[i];
            }
            return;
        }
        for(int i=m-1;i>=0;i--){
            A[i+n]=A[i];
        }
        int* be = B+n;
        int* ae = A+m+n;
        int* bs = B;
        int* as = A+n;
        int* p = A;
        int a = *as;
        int b = *bs;
        int mm;
        if(a<b){
            mm = a;
            as++;
        }else{
            mm = b;
            bs++;
        }
        *p++ = mm;
        while(as<ae&&bs<be){
            int aa = *as;
            int bb = *bs;
            if(aa<bb){
                *p++ = aa;
                as++;
            }else{
                *p++ = bb;
                bs++;
            }
        }
        if(as==ae){
            while(bs<be){
                *p++ = *bs++;
            }
        }
        if(bs==be){
            while(as<ae){
                *p++ = *as++;
            }
        }
        
    }
};