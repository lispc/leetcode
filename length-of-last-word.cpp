class Solution {
public:
    int lengthOfLastWord(const char *s) {
        
        if(!s)
        return 0;
        if(*s=='\0')
        return 0;
        auto p = s;
        int last = 0;
        int current = 0;
        char prev=' ';
        while(*p)
        {
            if(*p==' ')
            {
                if(prev!=' ')
                {
                    last = current;
                    current=0;
                }
            }
            else
            {
                current++;
            }
            prev=*p;
            p++;
        }
        if(prev==' ')
            return last;
        return current;
        
        
        /*
        auto p =s;
        auto t = p+strlen(p);
        t--;
        while(*t==' ')
        {
            if(t==p)
                return 0;
            else
            {
                
            }
            t--;
        }
        int cnt=0;
        while(*t!=' ')
        {
            if(t==p)
                return 0;
            else
            {
                cnt++;
            }
            t--;
        }
        //if(t==)
        return cnt;    
        */
        //return 0;
    }
};