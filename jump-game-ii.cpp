class Solution {
public:
    int jump(int A[], int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 0;
        }
        int step = 0;
        stack<pair<int,int>> q;
        q.push(make_pair(0,0));
        while(!q.empty()){
            step++;
            int st = q.top().first;
            int ed = q.top().second;
            q.pop();
            int next_max=ed;
            for(int i=st;i<=ed;i++){
                if(A[i]+i>next_max){
                    next_max = A[i]+i;
                }
            }
            if(next_max>=n-1){
                return step;
            }
            q.push(make_pair(ed+1,next_max));
        }
    }
};