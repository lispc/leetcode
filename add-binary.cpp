class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()){
            return addBinary(b,a);
        }
        string ra(a.rbegin(),a.rend());
        string rb(b.rbegin(),b.rend());
        string c;
        int carry = 0;
        for(int i=0;i<min(ra.size(),rb.size());i++){
            int s = ra[i]-'0'+rb[i]-'0'+carry;
            if(s>=2){
                carry = 1;
                s%=2;
            }else{
                carry = 0;
            }
            c.append(1,s+'0');
        }
        for(int i=rb.size();i<ra.size();i++){
            int s = ra[i]-'0'+carry;
              if(s>=2){
                carry = 1;
                s%=2;
            }else{
                carry = 0;
            }
            c.append(1,s+'0');
        }
        if(carry){
            c.append(1,'1');
        }
        return string(c.rbegin(),c.rend());
    }
};