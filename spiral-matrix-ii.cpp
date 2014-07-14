class Solution {
public:
    //vector<int> spiralOrder(vector<vector<int> > &matrix) {
     vector<vector<int> > generateMatrix(int n) {
        if(!n){
            vector<vector<int>> vvi;
            return vvi;
        }
        vector<vector<int>> res(n,vector<int>(n,0));
        int x = 0;
        int y = 0;
        int dir = 0;//1 2 3
        int data[4][2] = {0,1,1,0,0,-1,-1,0};
        int cur = 1;
        while(true){
            res[x][y]=cur++;
            int itry = 0;
            while(itry<4){
                int nx = x+data[dir][0];
                int ny = y+data[dir][1];
                if(0<=nx&&nx<n&&0<=ny&&ny<n&&res[nx][ny]==0){
                    x = nx;
                    y = ny;
                    break;
                }else{
                    dir = (dir+1)%4;
                    itry++;
                }
            }
            if(itry==4){
                break;
            }
        }
        return res;
    }
};