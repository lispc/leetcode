class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int x = matrix.size();
        if(!x){
            return false;
        }
        int y = matrix[0].size();
        if(!y){
            return false;
        }
        int st = 0;
        int ed = x;
        int xx;
        while(st<ed){
            if(st+1==ed){
                xx=st;
                break;
            }
            int mid = (st+ed)/2;
            int midv = matrix[mid][0];
            if(midv>target){
                ed = mid;
                continue;
            }else if(midv<target){
                st = mid;
                continue;
            }else{
                return true;
            }
        }
        st = 0;
        ed = y;
        while(st<ed){
            if(st+1==ed){
                return matrix[xx][st]==target;
            }
            int mid = (st+ed)/2;
            int midv = matrix[xx][mid];
            if(midv>target){
                ed = mid;
                continue;
            }else if(midv<target){
                st = mid;
                continue;
            }else{
                return true;
            }
        }
        
    }
};