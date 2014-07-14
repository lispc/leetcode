class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        char* t=haystack;
        char* p=needle;
        int lt=strlen(t);
        int lp=strlen(p);
        if(lp>lt)
            return NULL;
        for(;t<=haystack+lt-lp;t++)
        {
            if(!strncmp(t,p,lp))
                return t;
                
        }
        return NULL;
        
    }
};