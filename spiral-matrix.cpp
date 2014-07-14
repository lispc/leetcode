class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int h = matrix.size();
        if(!h){
            return res;
        }
        int w = matrix[0].size();
        if(!w){
            return res;
        }
        int x = 0;
        int y = 0;
        int dir = 0;//1 2 3
        int data[4][2] = {0,1,1,0,0,-1,-1,0};
        vector<vector<int>> m(h,vector<int>(w,0));
        while(true){
            m[x][y]=1;
            int v = matrix[x][y];
            res.push_back(v);
            int itry = 0;
            while(itry<4){
                int nx = x+data[dir][0];
                int ny = y+data[dir][1];
                if(0<=nx&&nx<h&&0<=ny&&ny<w&&m[nx][ny]==0){
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