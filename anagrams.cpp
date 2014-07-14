class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string,vector<int>> buf;
        int l = strs.size();
        for(int i=0;i<l;i++){
            string st = strs[i];
            sort(st.begin(),st.end());
            if(buf.find(st)!=buf.end()){
                buf[st].push_back(i);
            }else{
                buf[st] = vector<int>(1,i);
            }
        }
        for(auto it=buf.begin();it!=buf.end();it++){
            if(it->second.size()>1){
                for(int i=0;i<it->second.size();i++){
                    res.push_back(strs[it->second[i]]);
                }
            }
        }
        return res;
    }
};