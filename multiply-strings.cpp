class Solution {
public:
/*
    int 2i(char c)
    {
        
    }
    */
    string add(string s1,string s2)
    {
        int carry=0;
        int l1=s1.size();
        int l2=s2.size();
        if(l1<l2)
            return add(s2,s1);
        vector<char> cvec;
        l2--;
        l1--;
        while(l2>=0)
        {
            int i1=s1[l1]-'0';
            int i2=s2[l2]-'0';
            cvec.push_back('0'+(i1+i2+carry)%10);
            carry = (i1+i2+carry)/10;
            l1--;
            l2--;
        }
        if(l1==-1&&carry!=0)
            cvec.push_back('0'+carry);
        else
        {
            while(l1>=0)
            {
                cvec.push_back('0'+(s1[l1]-'0'+carry)%10);
                carry = (s1[l1]-'0'+carry)/10;
                l1--;
            }
            if(carry!=0)
                cvec.push_back('0'+carry);
        }
        return string(cvec.rbegin(),cvec.rend());
    }
    string m(string s1,int d)
    {
        vector<char> cvec;
        int l = s1.size()-1;
        int c=0;
        while(l>=0)
        {
            int i=s1[l]-'0';
            cvec.push_back('0'+(i*d+c)%10);
            c=(i*d+c)/10;
            l--;
        }
        if(c!=0)
        cvec.push_back(c+'0');
        return string(cvec.rbegin(),cvec.rend());
    }
    
    string multiply(string num1, string num2) {
        int l1=num1.size();
        int l2=num2.size();
        if(l1<l2)
            return multiply(num2,num1);
        string seed="0";
        for(int i=0;i<l2;i++)
        {
            seed=add(seed,m(num1,num2[i]-'0')+string(l2-1-i,'0'));
        }
        //return seed;
        auto i = seed.begin();
        while(*i=='0')
            i++;
        auto res = string(i,seed.end());
        return res==""?"0":res;
        
    }
};