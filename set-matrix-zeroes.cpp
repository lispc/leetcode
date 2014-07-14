class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        int hn = 0;
        int vn = 0;
        for(int i=0;i<w;i++){
            if(matrix[0][i]==0){
                hn = 1;
                break;
            }
        }
        for(int i=0;i<h;i++){
            if(matrix[i][0]==0){
                vn = 1;
                break;
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<h;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<w;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=1;j<w;j++){
            if(matrix[0][j]==0){
                for(int i=1;i<h;i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(hn){
            for(int i=0;i<w;i++){
                matrix[0][i]=0;
            }
        }
        if(vn){
            for(int i=0;i<h;i++){
                matrix[i][0]=0;
            }
        }
    }
};