class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        vector<vector<int>> res;
        int gnear = num[0]+num[1]+num[2];
        sort(num.begin(),num.end());
        int last = num[0];
        for(int i=0;i<num.size()-2;i++){
            if(i&&num[i]==last){
                continue;
            }
            last = num[i];
            int st = i+1;
            int ed = num.size()-1;
            int neg = target-num[i];
            int this_sum = num[st]+num[ed];
            while(st<ed){
                int s = num[st]+num[ed];
                if(s==neg){
                    return target;
                }
                if(abs(s-neg)<abs(this_sum-neg)){
                    this_sum = s;
                }
                if(s<neg){
                    st++;
                }else{
                    ed--;
                }
            }
            int this_near = num[i]+this_sum;
            if(abs(this_near-target)<abs(gnear-target)){
                gnear = this_near;
            }
        }
        return gnear;
    }
};