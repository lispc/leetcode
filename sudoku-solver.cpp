class Solution {
public:
    int board[9][9];
    int x_mark[9][10];
    int y_mark[9][10];
    int sq_mark[3][3][10];
    bool search(){
    	bool full = true;
    	for(int i=0;i<9;i++){
    		for(int j=0;j<9;j++){
    			if(full==false){
    				return false;
    			}
    			int v = board[i][j];
    			if(v==0){
    				full = false;
    				for(int k=1;k<=9;k++){
    					if(x_mark[i][k]==0&&y_mark[j][k]==0&&sq_mark[i/3][j/3][k]==0){
    						x_mark[i][k]=1;
    						y_mark[j][k]=1;
    						sq_mark[i/3][j/3][k]=1;
    						board[i][j]=k;
    						bool res = search();
    						if(res){
    							return res;
    						}
    						x_mark[i][k]=0;
    						y_mark[j][k]=0;
    						sq_mark[i/3][j/3][k]=0;
    						board[i][j]=0;
    					}
    				}
    			}
    		}
    	}
    	if(full){
    		return true;
    	}else{
    		return false;
    	}
    }
    void solveSudoku(vector<vector<char> > &tboard) {
        /*
        for(int i=0;i<9;i++){
			for(int j=0;j<=9;j++){
			    board[i][j]=tboard[i][j]-'0';
			}
		}*/
		for(int i=0;i<9;i++){
			for(int j=0;j<=9;j++){
				x_mark[i][j]=0;
				y_mark[i][j]=0;
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<=9;k++){
					sq_mark[i][j][k]=0;
				}
			}
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
			    char s = tboard[i][j];
				if(s!='.'){
					int v = s-'0';
					board[i][j]=v;
					x_mark[i][v]=1;
					y_mark[j][v]=1;
					sq_mark[i/3][j/3][v]=1;
				}else{
					board[i][j]=0;
				}
			}
		}
		bool res = search();
		for(int i=0;i<9;i++){
			for(int j=0;j<=9;j++){
			    tboard[i][j]=board[i][j]+'0';
			}
		}
    }
};