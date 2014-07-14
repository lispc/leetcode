class Solution {
public:
    double pow(double x, int n) {
        if(!n)
            return 1;
        if(n>0)
        {
            auto d = pow(x,n/2);
            return n%2?d*d*x:d*d;
        }
        if(n==-2147483648)
            return 1/(pow(x,2147483647)*x);
            return 1/pow(x,-n);
    }
};