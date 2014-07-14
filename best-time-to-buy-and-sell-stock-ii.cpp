class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int s = prices.size();
        if(s==0){
            return 0;
        }
        vector<int> delta(s-1,0);
        int sum = 0;
        for(int i=0;i<s-1;i++){
            delta[i]=prices[i+1]-prices[i];
            if(delta[i]>0){
                sum+=delta[i];
            }
        }
        return sum;
        
    }
};