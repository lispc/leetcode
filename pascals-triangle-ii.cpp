class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);
        if(rowIndex<=1){
            return res;
        }
        for(int i=2;i<=rowIndex;i++){
            for(int j=i-1;j>0;j--){
                res[j]=res[j]+res[j-1];
            }
        }
        return res;
        
    }
};