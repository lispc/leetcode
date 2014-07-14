class Solution {
public:
    bool isValid(string s) {
        const char* p=s.c_str();
        vector<char> stack;
        while(*p)
        {
            char c=*p;
            if(c=='('||c=='['||c=='{')
            {
                stack.push_back(c);
                p++;
                continue;
                //p++;
            }
            if(stack.empty())
                return false;
            if(c==']'&&stack.back()=='['\
            ||c==')'&&stack.back()=='('\
            ||c=='}'&&stack.back()=='{')
            p++,stack.pop_back();
            else
                return false;
            
                
        }
        return stack.empty();
        
    }
};