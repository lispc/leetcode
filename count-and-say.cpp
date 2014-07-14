class Solution {
public:
    string it(string s)
    {
        stringstream ss;
        int l = s.size();
        char prev=s[0];
        int cnt=1;
        for(int i=1;i<l;i++)
        {
            if(s[i]!=prev)
            {
                ss<<cnt<<prev;
                cnt=1;
                prev=s[i];
            }
            else
            {
                cnt++;
            }
        }
        ss<<cnt<<prev;
        return ss.str();
    }
    string countAndSay(int n) {
        string seed="1";
        while(--n)
        {
            seed=it(seed);
        }
        return seed;
    }
};