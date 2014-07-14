class Solution {
public:
    vector<vector<bool>> cy;
    string gs;
    int gl;
    bool cal(int st,int ed){
        if(ed-st<=1){
            cy[st][ed]=true;
            return true;
        }
        if(gs[st]==gs[ed-1]){
            if(cy[st+1][ed-1]||st+2==ed){
                cy[st][ed]=true;
                return true;
            }
        }
        return false;
        
    }
    int minCut(string s) {
        gs = s;
        int l = s.size();
        gl = l;
        cy = vector<vector<bool>>(l+1,vector<bool>(l+1,false));
        if(l<=1){
            return 0;
        }
        vector<int> dp(l+1,0);
        dp[0]=-1;
        for(int i=2;i<=l;i++){
            dp[i]=i-1;
            for(int j=i;j>=1;j--){
                if(cal(j-1,i)){
                    int v = 1+dp[j-1];
                    if(v<dp[i]){
                        dp[i]=v;
                    }
                }
            }
        }
        return dp[l];
    }
};