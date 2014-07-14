class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        if(x<0){
            flag = -1;
            x = -x;
        }
        int seed = 0;
        while(x){
            seed*=10;
            int r = x%10;
            seed+=r;
            x/=10;
        }
        return flag*seed;
        
        
    }
};