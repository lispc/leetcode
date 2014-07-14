class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> sc;
        int l = s.size();
        if(l<=1){
            return l;
        }
        //int st = 1;//to handle
        //int ed = 0;
        sc[s[0]]=0;
        int gmax = 1;
        int cur_len = 1;
        int cur = 1;
        while(cur<l){
            char c = s[cur];
            if(sc.find(c)==sc.end()){
                cur_len++;
                sc[c]=cur;
                cur++;
                continue;
            }else{
                if(cur_len>gmax){
                    gmax = cur_len;
                }
                int pre = sc[c];
                int cur_start = cur-cur_len;
                for(int t=cur_start;t<=pre;t++){
                    if(sc.find(s[t])!=sc.end()){
                        sc.erase(s[t]);
                    }
                }
                cur_len = cur-pre;
                sc[c] = cur;
                cur++;
                continue;
            }
        }
        if(cur_len>gmax){
            gmax = cur_len;
        }
        return gmax;
    }
};