class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int x = board.size();
        if(!x){
            return;
        }
        int y = board[0].size();
        if(!y){
            return;
        }
        vector<vector<int>> av(x,vector<int>(y,0));
        stack<pair<int,int>> sk;
        for(int i=0;i<y;i++){
            if(board[0][i]=='O'){
                sk.push(make_pair(0,i));
                av[0][i]=1;
            }
        }
        if(x!=1)
        for(int i=0;i<y;i++){
            if(board[x-1][i]=='O'){
                sk.push(make_pair(x-1,i));
                av[x-1][i]=1;
            }
        }
        for(int i=1;i<x-1;i++){
            if(board[i][0]=='O'){
                sk.push(make_pair(i,0));
                av[i][0]=1;
            }
        }
        if(y!=1)
        for(int i=1;i<x-1;i++){
            if(board[i][y-1]=='O'){
                sk.push(make_pair(i,y-1));
                av[i][y-1]=1;
            }
        }
        int dir[4][2] = {1,0,-1,0,0,-1,0,1};
        while(!sk.empty()){
            int xx = sk.top().first;
            int yy = sk.top().second;
            sk.pop();
            for(int d=0;d<4;d++){
                int nx = xx + dir[d][0];
                int ny = yy + dir[d][1];
                if(0<=nx&&nx<x&&0<=ny&&ny<y&&board[nx][ny]=='O'){
                    if(!av[nx][ny]){
                        av[nx][ny]=1;
                        sk.push(make_pair(nx,ny));
                    }
                }
            }
        }
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(!av[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};