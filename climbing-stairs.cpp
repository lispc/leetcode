class Solution {
public:
    vector<int> * p;
    /*0>1 1->1 2>2)*/
    int climbStairs(int n) {
        //p = new vector<int>(n+1)
        int f = 1;
        int b = 1;
        int s = 1;
        while(f<n)
        {
            b=b+s;
            s=b-s;
            f++;
        }
        return b;
    }
};