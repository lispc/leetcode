class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0){
            return "";
        }
        string res = strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            for(;j<min(strs[i].size(),res.size());j++){
                if(strs[i][j]!=res[j]){
                    break;
                }
            }
            res = res.substr(0,j);
        }
        return res;
    }
};