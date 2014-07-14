class Solution {
public:
    vector<int> xm;
    vector<int> ym;
    vector<vector<int>> board;
    vector<int> em;
    vector<int> wm;
    int n;
    int gete(int x,int y){
        return x+y;//0-14
    }
    int getw(int x,int y){
        return (x-y+2*n)%(2*n);//[-7,7] , [9,10,15]
    }
    int cnt;
    void dfs(int i){
        if(i==n){
            cnt++;
            return;
        }
        for(int j=0;j<n;j++){
            if(!ym[j]&&!em[gete(i,j)]&&!wm[getw(i,j)]){
                ym[j]=1;
                em[gete(i,j)]=1;
                wm[getw(i,j)]=1;
                board[i][j]=1;
                dfs(i+1);
                ym[j]=0;
                em[gete(i,j)]=0;
                wm[getw(i,j)]=0;
                board[i][j]=0;
            }
        }
        
    }
    void solveNQueens(int n) {
        this->n=n;
        xm=vector<int>(n,0);
        ym=vector<int>(n,0);
        board=vector<vector<int>>(n,vector<int>(n,0));
        em=vector<int>(2*n,0);
        wm=vector<int>(2*n,0);
        dfs(0);
    }
    int totalNQueens(int n) {
        cnt=0;
        solveNQueens(n);
        return cnt;
        
    }
};