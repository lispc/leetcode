class Solution {
public:
    string data[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> vs;
        int size = digits.size();
        if(size==0){
            vs.push_back("");
            return vs;
        }
        if(size==1){
            int v = digits[0]-'0';
            for(int i=0;i<data[v].size();i++){
                vs.push_back(string(1,data[v][i]));
            }
            return vs;
        }
        auto rr = letterCombinations(digits.substr(1));
        int v = digits[0]-'0';
        for(int i=0;i<data[v].size();i++){
            for(int j=0;j<rr.size();j++){
                string ss(1,data[v][i]);
                ss.append(rr[j]);
                vs.push_back(ss);
            }
        }
        return vs;
    }
};