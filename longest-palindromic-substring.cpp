class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.size();
        int gst = 0;
        int ged = 1;
        int gmax = 1;
        for(int i=1;i<l-1;i++){
            int st = i-1;
            int ed = i+1;
            int ll = 1;
            while(st>=0&&ed<l){
                if(s[st]!=s[ed]){
                    break;
                }
                ll+=2;
                st--;
                ed++;
            }
            if(ll>gmax){
                gst = st+1;
                ged = ed-1;
                gmax = ll;
            }
        }
        for(int i=1;i<l;i++){
            int st = i-1;
            int ed = i;
            int ll = 0;
            while(st>=0&&ed<l){
                if(s[st]!=s[ed]){
                    break;
                }
                ll+=2;
                st--;
                ed++;
            }
            if(ll>gmax){
                gst = st+1;
                ged = ed-1;
                gmax=ll;
            }
        }
        return s.substr(gst,ged-gst+1);
    }
};