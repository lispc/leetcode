class Solution {
public:
    string minWindow(string S, string T) {
        int sl = S.size();
        int tl = T.size();
        if(!tl){
            return "";
        }
        if(sl<tl){
            return "";
        }
        if(tl==1){
            for(int i=0;i<sl;i++){
                if(S[i]==T[0]){
                    return T;
                }
            }
            return "";
        }
        map<char,int> tbuf;
        map<char,int> buf;
        for(int i=0;i<tl;i++){
            char c = T[i];
            if(tbuf.find(c)==tbuf.end()){
                tbuf[c]=1;
            }else{
                tbuf[c]++;
            }
        }
        int cnt = 0;
        int i = 0;
        for(;i<sl;i++){
            char c = S[i];
            if(tbuf.find(c)==tbuf.end()){
                continue;
            }
            if(buf.find(c)==buf.end()){
                buf[c]=1;
            }else{
                buf[c]++;
            }
            if(buf[c]==tbuf[c]){
                cnt++;
            }
            if(cnt==tbuf.size()){
                break;
            }
        }
        if(i==sl){
            return "";
        }
        int st = 0;
        int ed = i;
        int gmin;
        int minst;
        int mined;
        while(1){
            char c = S[st];
            if(tbuf.find(c)==tbuf.end()){
                st++;
                continue;
            }
            if(buf[c]==tbuf[c]){
                break;
            }else{
                buf[c]--;
                st++;
            }
        }
        gmin = ed-st+1;
        minst = st;
        mined = ed;
        while(ed<sl){
            char c = S[st];
            buf[c]--;
            ed++;
            while(ed<sl){
                char sc = S[ed];
                if(buf.find(sc)!=buf.end()){
                    buf[sc]++;
                }
                if(S[ed]==c){
                    break;
                }
                ed++;
            }
            if(ed==sl){
                break;
            }
            st++;
            while(1){
                char c = S[st];
                if(tbuf.find(c)==tbuf.end()){
                    st++;
                    continue;
                }
                if(buf[c]==tbuf[c]){
                    break;
                }else{
                    buf[c]--;
                    st++;
                }
            }
            if(ed-st+1<gmin){
                gmin = ed-st+1;
                minst = st;
                mined = ed;
            }
        }
        return S.substr(minst,gmin);
    }
};