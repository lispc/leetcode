class Solution {
public:
    int atoi(const char *str) {
        int mmax = 2147483647;
        int tend = mmax/10;
        int mmin = -2147483648;
        int res = 0;
        if(!str){
            return 0;
        }
        int l = strlen(str);
        if(!l){
            return 0;
        }
        int offset = 0;
        int head = 1;
        int need_sign = 1;
        int sign = 1;
        while(offset<l){
            char c = str[offset++];
            if(c==' '){
                if(head){
                    continue;
                }else{
                    break;
                }
            }
            head = 0;
            if(c=='+'||c=='-'){
                if(need_sign){
                    need_sign = 0;
                    if(c=='-'){
                        sign = -1;
                    }
                    continue;
                }else{
                    break;
                }
            }
            if(isdigit(c)){
                int res_bak = res;
                res*=10;
                res+=c-'0';
                if(res/10!=res_bak||res%10!=c-'0'){
                    return sign==1?mmax:mmin;
                }
            }else{
                break;
            }
        }
        return sign*res;
        
    }
};