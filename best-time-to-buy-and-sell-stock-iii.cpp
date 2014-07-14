class Solution {
public:
    int isum(vector<int>::iterator st,vector<int>::iterator ed,int&rst,int&red){
        rst = 0;
        red = 0;
        auto d = vector<int>(st,ed);
        int s = d.size();
        if(s==0){
            return 0;
        }
        if(s==1){
            if(*st>0){
                red=1;
                return*st;
            }
            return 0;
        }
        int mp = d[0];
        int auc = 0;
        red = 1;
        int this_start = 0;
        for(int i=0;i<s;i++){
            auc += d[i];
            if(auc<=0){
                this_start = i+1;
                auc = 0;
                continue;
            }
            if(auc>mp){
                rst = this_start;
                red = i+1;
                mp = auc;
            }
        }
        return max(0,mp);
        
    }
    int maxProfit(vector<int> &prices) {
        int s = prices.size();
        if(s<=1){
            return 0;
        }
        int st = 0;
        while(st<s-1&&prices[st]>=prices[st+1]){
            st++;
        }
        int ed = s-1;
        while(ed>0&&prices[ed]<=prices[ed-1]){
            ed--;
        }
        if(ed<st){
            return 0;
        }
        vector<int> d;
        for(int i=st;i<=min(ed,s-2);i++){
            d.push_back(prices[i+1]-prices[i]);
        }
        int dl = d.size();
        if(!dl){
            return d[0]>0?d[0]:0;
        }
        int a,b;
        int gmax = 0;
        for(int i=0;i<dl;i++){
            int v1 = isum(d.begin(),d.begin()+i,a,b);
            int v2 = isum(d.begin()+i,d.end(),a,b);
            if(v1+v2>gmax){
                gmax = v1+v2;
            }
        }
        return gmax;
        
    }
};