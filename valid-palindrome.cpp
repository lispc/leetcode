class Solution {
public:
    bool isPalindrome(string s) {
        if(s==""){
            return true;
        }
        int l = s.size();
        int st = 0;
        int ed = l-1;
        while(true){
            while(st<l&&!isalnum(s[st])){
                st++;
            }
            while(ed>=0&&!isalnum(s[ed])){
                ed--;
            }
            if(st>=ed){
                return true;
            }
            if(tolower(s[st])!=tolower(s[ed])){
                return false;
            }
            st++;
            ed--;
        }
    }
};