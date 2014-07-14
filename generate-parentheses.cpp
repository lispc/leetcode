class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> svec;
        if(n==0)
        {
            svec.push_back("");
            return svec;
        }
        for(int i=1;i<=n;i++)
        {
            auto prefix = rec(i);
            auto suffix = generateParenthesis(n-i);
            for(auto x=begin(prefix);x!=end(prefix);x++)
            for(auto y=begin(suffix);y!=end(suffix);y++)
            svec.push_back(*x+*y);
            
        }
        return svec;
    }
    vector<string> rec(int n)
    {
        
         vector<string> svec;
         //if(n==1)
         //{svec.push_back("()");
         //return svec;}
        auto a=generateParenthesis(n-1);
        for(auto i=a.begin();i!=a.end();i++)
        {
            svec.push_back("("+*i+")");
        }
        return svec;
    }
};