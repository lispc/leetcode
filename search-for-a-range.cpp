class Solution {
public:
    int lf(int*ps,int*pe,int t){
        if(ps==pe){
            return -1;
        }
        if(ps+1==pe){
            return *ps==t?0:-1;
        }
        if(ps+2==pe){
            return *ps==t?0:(*(ps+1)==t?1:-1);
        }
        int* mid = ps+(pe-ps)/2;
        if(*mid==t){
            return lf(ps,mid+1,t);
        }else if(*mid<t){
            int l = lf(mid+1,pe,t);
            if(l==-1){
                return -1;
            }else{
                return mid-ps+1+l;
            }
        }else{
            return lf(ps,mid,t);
        }
    }
    int rf(int*ps,int*pe,int t){
        if(ps==pe){
            return -1;
        }
        if(ps+1==pe){
            return *ps==t?0:-1;
        }
        int* mid = ps+(pe-ps)/2;
        if(*mid==t){
            return (mid-ps)+rf(mid,pe,t);
        }else if(*mid<t){
            int l = rf(mid,pe,t);
            if(l==-1){
                return -1;
            }else{
                return mid-ps+l;
            }
        }else{
            return rf(ps,mid,t);
        }
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        if(n==0){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        if(n==1){
            if(A[0]==target){
                res.push_back(0);
                res.push_back(0);
            }else{
                res.push_back(-1);
                res.push_back(-1);
            }
            return res;
        }
        int s = lf(A,A+n,target);
        int e = rf(A,A+n,target);
        res.push_back(s);
        res.push_back(e);
        return res;
        
    }
};