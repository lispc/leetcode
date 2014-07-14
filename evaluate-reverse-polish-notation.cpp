class Solution {
public:
    int evalRPN(vector<string> &tokens) {
      auto i=tokens.begin();
      vector<int> ivec;
      while(i!=tokens.end())
        {
            string s = *i;
            if(s=="+")
            {
                int x=ivec.back();
                ivec.pop_back();
                int y=ivec.back();
                ivec.pop_back();
                ivec.push_back(x+y);
            }
            else if(s=="-")
            {
                 int x=ivec.back();
                ivec.pop_back();
                int y=ivec.back();
                ivec.pop_back();
                ivec.push_back(y-x);
            }
            else if(s=="*")
            {
                 int x=ivec.back();
                ivec.pop_back();
                int y=ivec.back();
                ivec.pop_back();
                ivec.push_back(x*y);
            }
            else if(s=="/")
            {
                 int x=ivec.back();
                ivec.pop_back();
                int y=ivec.back();
                ivec.pop_back();
                ivec.push_back(y/x);
            }
            else 
                ivec.push_back(stoi(s));
            i++;
        }
        return ivec[0];
    }
};