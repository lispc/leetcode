class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res;
        if(!numRows){
            return res;
        }
        res.push_back(vector<int>(1,1));
        if(numRows==1){
            return res;
        }
        for(int i=2;i<=numRows;i++){
            vector<int> row(i,0);
            row[0]=1;
            row[i-1]=1;
            for(int j=1;j<i-1;j++){
                row[j]=res[i-2][j]+res[i-2][j-1];
            }
            res.push_back(row);
        }
        return res;
    }
};