class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        auto xm = vector<vector<int>>(9,vector<int>(10,0));
        auto ym = vector<vector<int>>(9,vector<int>(10,0));
        auto sm = vector<vector<int>>(9,vector<int>(10,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                if(c=='.'){
                    continue;
                }
                int v = c-'0';
                int s = (i/3)*3+(j/3);
                if(xm[i][v]){
                    return false;
                }
                xm[i][v]=1;
                if(ym[j][v]){
                    return false;
                }
                ym[j][v]=1;
                if(sm[s][v]){
                    return false;
                }
                sm[s][v]=1;
            }
        }
        
    }
};