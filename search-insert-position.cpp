class Solution {
public:
    int rec(int*ps,int*pe,int t){
        if(ps==pe){
            return 0;
        }
        if(ps+1==pe){
            if(*ps==t){
                return 0;
            }else{
                return *ps<t?1:0;
            }
        }
        int* mid = ps+(pe-ps)/2;
        if(*mid==t){
            return mid-ps;
        }else if(*mid>t){
            return rec(ps,mid,t);
        }else{
            return mid-ps+rec(mid,pe,t);
        }
    }
    int searchInsert(int A[], int n, int target) {
        return rec(A,A+n,target);
    }
};