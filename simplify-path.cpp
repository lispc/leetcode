class Solution {
public:
    string simplifyPath(string path) {
        vector<string> buf;
        path.append("/");
        int l = path.size();
        int last = 0;
        for(int i=1;i<l;i++){
            if(path[i]=='/'){
                string seg = path.substr(last+1,i-last-1);
                last = i;
                if(seg==""||seg=="."){
                    continue;
                }
                if(seg==".."){
                    if(!buf.empty()){
                        buf.pop_back();
                    }
                    continue;
                }
                buf.push_back(seg);
            }
        }
        string res;
        if(buf.size()==0){
            return "/";
        }
        for(int i=0;i<buf.size();i++){
            res.append("/");
            res.append(buf[i]);
        }
        return res;
    }
};