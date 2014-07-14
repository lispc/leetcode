class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int x = matrix.size();
        if(!x){
            return 0;
        }
        int y = matrix[0].size();
        if(!y){
            return 0;
        }
        vector<vector<int>> dp(x,vector<int>(y,0));
        for(int i=0;i<x;i++){
            if(matrix[i][y-1]=='1'){
                dp[i][y-1]=1;
            }
            for(int j=y-2;j>=0;j--){
                if(matrix[i][j]=='1'){
                    dp[i][j]=dp[i][j+1]+1;
                }else{
                    dp[i][j]=0;
                }
            }
        }
        int gmax = 0;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(matrix[i][j]!='1'){
                    continue;
                }
                int local_max = dp[i][j];
                int local_min = dp[i][j];
                for(int k=i+1;k<x;k++){
                    local_min = min(dp[k][j],local_min);
                    if(local_min==0){
                        break;
                    }
                    int new_area = (k-i+1)*local_min;
                    local_max = max(local_max,new_area);
                }
                gmax = max(gmax,local_max);
            }
        }
        return gmax;
    }
};