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
    bool search(int A[], int n, int target) {
        if(n<=2){
            for(int i=0;i<n;i++){
                if(A[i]==target){
                    return true;//i;
                }
            }
            return false;//-1;
        }
        int cut = 0;
        if(A[0]<A[n-1]){
            return bf(A,A+n,target)==-1?false:true;
        }
        int s = 0;
        int e = n-1;
        while(s<e){
            if(s+1==e){
                if(A[s]<=A[e]){
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
            }else if(mv>ev){
                s = mid;
            }else{
                s = s+1;
            }
        }
        auto lr = bf(A,A+cut,target);
        if(lr!=-1){
            return true;//lr;
        }
        auto rr = bf(A+cut,A+n,target);
        if(rr!=-1){
            return true;//cut+rr;
        }
        return false;//-1;
        
    }
};