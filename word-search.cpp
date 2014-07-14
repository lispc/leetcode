class Solution {
public:
    vector<vector<char>> gb;
    vector<vector<int>> mk;
    int x;
    int y;
    string s;
    int l;
    int dir[4][2];
    bool dfs(int cx,int cy,int offset){
        if(offset==l){
            return true;
        }
        for(int d=0;d<4;d++){
            int nx = cx+dir[d][0];
            int ny = cy+dir[d][1];
            if(0<=nx&&nx<x&&0<=ny&&ny<y&&mk[nx][ny]==0&&gb[nx][ny]==s[offset]){
                mk[nx][ny]=1;
                bool res = dfs(nx,ny,offset+1);
                if(res){
                    return true;
                }
                mk[nx][ny]=0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        gb = board;
        s = word;
        l = word.size();
        if(word==""){
            return true;
        }
        x = board.size();
        if(!x){
            return false;
        }
        y = board[0].size();
        if(!y){
            return false;
        }
        mk = vector<vector<int>>(x,vector<int>(y,0));  
        // = {1,0,-1,0,0,1,0,-1};
        dir[0][0]=1;
        dir[0][1]=0;
        dir[1][0]=-1;
        dir[1][1]=0;
        dir[2][0]=0;
        dir[2][1]=1;
        dir[3][0]=0;
        dir[3][1]=-1;
        for(int xx=0;xx<x;xx++){
            for(int yy=0;yy<y;yy++){
                if(board[xx][yy]!=word[0]){
                    continue;
                }
                mk[xx][yy]=1;
                bool res = dfs(xx,yy,1);
                if(res){
                    return true;
                }
                mk[xx][yy]=0;
            }
        }
        return false;
    }
};