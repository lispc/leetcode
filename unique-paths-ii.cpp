class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();//1
        int n = obstacleGrid[0].size();//2
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(obstacleGrid[0][0]==0){
            dp[0][0]=1;
        };
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1){
                break;
            }
            dp[i][0]=1;
        }
         for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]==1){
                break;
            }
            dp[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};