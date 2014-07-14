class Solution {
public:
    int rec(int*A,int m,int*B,int n,int loc){
        if(!m){
            return B[loc];
        }
        if(!n){
            return A[loc];
        }
        if(m>n){
            return rec(B,n,A,m,loc);
        }
        if(n==1){
            return loc?max(*A,*B):min(*A,*B);
        }
        int bmid = n/2;
        int bmv = B[bmid];
        int pos = upper_bound(A,A+m,bmv)-A;
        int index = bmid+pos;
        if(index==loc){
            return bmv;
        }else if(index<loc){
            return rec(A+pos,m-pos,B+bmid,n-bmid,loc-index);
        }else{
            return rec(A,pos,B,bmid,loc);
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return (rec(A,m,B,n,(m+n-1)/2)+rec(A,m,B,n,(m+n)/2))/2.0;
    }
};