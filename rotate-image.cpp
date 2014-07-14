class Solution {
public:
    
    void rotate(vector<vector<int> > &matrix) {//4-1 3-1 5-2 6-2
        int n = matrix.size();
        for(int i=0;i<=n/2-1;i++){//5-1 4-1 3-0 2-0
            for(int j=0;j<=(n-1)/2;j++){//0 1 n = 3
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];//01 10 
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];//10 21
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];//21 12
                matrix[j][n-1-i] = temp;//12 
            }
        }
    }
};