class Solution {
public:
    bool check1(char c){
        return c!='0';
    }
    bool check1(string s1){
        check1(s1[0]);
    }
    bool check2(string s2){
        char c1 = s2[0];
        char c2 = s2[1];
        if(c1=='0'){
            return false;
        }
        if(c1>'2'){
            return false;
        }
        if(c1=='1'){
            return true;
        }
        return c2<='6';
    }
    int numDecodings(string s) {
        int l = s.size();
        if(l==0){
            return 0;
        }
        if(l==1){
            return check1(s);
        }
        if(l==2){
            return int(check1(s[0])&&check1(s[1]))+int(check2(s));
        }
        vector<int> buf(l,0);
        buf[0]=check1(s[0]);
        for(int i=1;i<l;i++){
            if(check1(s[i])){
                buf[i]+=buf[i-1];
            }
            if(check2(s.substr(i-1,2))){
                buf[i]+=(i==1)?1:buf[i-2];
            }
        }
        return buf[l-1];
        
    }
};