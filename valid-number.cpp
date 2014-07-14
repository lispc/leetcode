class Solution {
public:
    bool num(char*st,char*ed){
        if(st==ed){
            return false;
        }
        while(st!=ed){
            if(!isdigit(*st)){
                return false;
            }
            st++;
        }
        return true;
    }
    bool _isNumber(char *s) {
        if(!s){
            return false;
        }
        auto cur = s;
        while(*cur){
            cur++;
        }
        cur--;
        while(cur>=s&&*cur==' '){
            cur--;
        }
        *(cur+1)=0;
        auto p = s;
        while(*p==' '){
            p++;
        }
        if(*p=='+'||*p=='-'){
            p++;
        }
        if(cur<p){
            return false;
        }
        char*pp = NULL;
        char*pe = NULL;
        auto it = p;
        while(*it){
            if(pp&&pe){
                break;
            }
            if(*it=='e'&&!pe){
                pe = it;
            }
            if(*it=='.'&&!pp){
                pp = it;
            }
            it++;
        }
        if(!pp&&!pe){
            return num(p,cur+1);
        }
        if(!pe&&pp){
            return (p==pp||num(p,pp))&&(pp==cur||num(pp+1,cur+1))&&p!=cur;
        }
        auto ppee = pe;
        if(*(pe+1)=='+'||*(pe+1)=='-'){
            ppee++;
        }
        if(pe&&!pp){
            return num(p,pe)&&num(ppee+1,cur+1);
        }
        return ((p==pp||num(p,pp))&&(pp+1==pe||num(pp+1,pe))&&p+1!=pe)&&num(ppee+1,cur+1);
        
    }
    bool isNumber(const char* s){
        char* ns = new char[strlen(s)+1];
        strcpy(ns,s);
        return _isNumber(ns);
    }
};