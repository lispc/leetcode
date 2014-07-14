class Solution {
public:
    int divide(int dividend, int divisor) {
        /*
        if(dividend<0)
            return -divide(-dividend,divisor);
        if(divisor<0)
            return -divide(dividend,-divisor);
        if(dividend<divisor)
            return 0;
        //int r=0;
        int res=1;
        int dd=divisor;
        while(dividend>dd+dd)
        {
            //dividend-=divisor;
            //r++;
            dd+=dd;
            res+=res;
        }
        return res+divide(dividend-dd,divisor);
        //return r;
        */
        return dividend/divisor;
    }
};