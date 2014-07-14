class Solution {
public:
    int sqrt(int x) {
        //int t=x/2;
        //if
        if(x==0||x==1)
            return x;
        return sqrt(x,1,x);
    }
    
    unsigned long long sqrt(unsigned long long x,unsigned long long s,unsigned long long e)
    {
        if(s+1==e)
            return s;
        unsigned long long m=(s+e)/2;
        unsigned long long q=m*m;
        if(q==x)
            return m;
        if(q<x)
            return sqrt(x,m,e);
        if(q>x)
            return sqrt(x,s,m);
    }
};