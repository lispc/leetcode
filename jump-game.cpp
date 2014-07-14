class Solution {
public:
    bool canJump(int A[], int n) {
        int lb = 0;
        int rb = 0;
        while(lb<=rb)
        {
            int nrb = lb+A[lb];
            rb = rb>nrb?rb:nrb;
            if(rb>=n-1)
                return true;
            lb++;
        }
        return false;
        
    }
};