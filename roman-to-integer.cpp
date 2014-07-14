class Solution {
public:
    char data[3][3]= {{'I','V','X'},{'X','L','C'},{'C','D','M'}};
    int tens[3] = {1,10,100};
    int parse(string& s,int p){
        if(s==""){
            return 0;
        }
        char s0 = s[0];
        if(s0!=data[p][0]&&s0!=data[p][1]&&s0!=data[p][2]){
            return parse(s,p-1);
        }
        if(s0==data[p][1]){
            s = s.substr(1);
            return 5*tens[p]+parse(s,p);
        }
        if(s.size()==1){
            return tens[p];
        }
        char s1 = s[1];
        if(s1==data[p][2]){
            s = s.substr(2);
            return 9*tens[p]+parse(s,p-1);
        }
        if(s1==data[p][1]){
            s = s.substr(2);
            return 4*tens[p]+parse(s,p-1);
        }
        int cnt = 1;
        while(s[cnt]==data[p][0]){
            cnt++;
        }
        s = s.substr(cnt);
        return cnt*tens[p]+parse(s,p-1);
    }
    int romanToInt(string s) {
        int th = 0;
        int res = 0;
        while(s[th]=='M'){
            th++;
        }
        res+=th*1000;
        s = s.substr(th);
        return res+parse(s,2);
    }
};