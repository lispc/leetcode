class Solution {
public:
    int bf(int*ps,int*pe,int t){
        auto it = lower_bound(ps,pe,t);
        if(it==pe){
            return -1;
        }
        if(*it!=t){
            return -1;
        }
        return it-ps;
    }
    int search(int A[], int n, int target) {
        if(n<=2){
            for(int i=0;i<n;i++){
                if(A[i]==target){
                    return i;
                }
            }
            return -1;
        }
        int cut = 0;
        if(A[0]<A[n-1]){
            return bf(A,A+n,target);
        }
        int s = 0;
        int e = n-1;
        while(s<e){
            if(s+1==e){
                if(A[s]<A[e]){
                    cut = s;
                }else{
                    cut = e;
                }
                break;
            }
            int sv = A[s];
            int ev = A[e];
            int mid = (s+e)/2;
            int mv = A[mid];
            if(mv<sv){
                e = mid;
                continue;
            }else{
                s = mid;
            }
        }
        auto lr = bf(A,A+cut,target);
        if(lr!=-1){
            return lr;
        }
        auto rr = bf(A+cut,A+n,target);
        if(rr!=-1){
            return cut+rr;
        }
        return -1;
        
    }
};