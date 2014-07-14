class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int s = prices.size();
        if(s<=1){
            return 0;
        }
        vector<int> d(s-1,0);
        for(int i=0;i<s-1;i++){
            d[i]=prices[i+1]-prices[i];
        }
        int mp = d[0];
        int auc = 0;
        for(int i=0;i<s-1;i++){
            auc += d[i];
            if(auc<=0){
                auc = 0;
                continue;
            }
            if(auc>mp){
                mp = auc;
            }
        }
        return max(0,mp);
        
    }
};