class Solution {
public:
    string convert(string s, int nRows) {
        if(s==""){
            return "";
        }
        if(nRows==1){
            return s;
        }
        int seg_len = 2*nRows-2;
        int l = s.size();
        int seg_num = l/seg_len;
        int rr = l%seg_len;
        string res;
        for(int i=0;i<seg_num;i++){
            res.append(1,s[i*seg_len]);
        }
        if(rr){
            res.append(1,s[seg_len*seg_num]);
        }
        for(int i=1;i<nRows-1;i++){
            int o1 = i;
            int o2 = seg_len - i;
            for(int j=0;j<seg_num;j++){
                res.append(1,s[j*seg_len+o1]);
                res.append(1,s[j*seg_len+o2]);
            }
            if(rr>o1){
                res.append(1,s[seg_len*seg_num+o1]);
            }
            if(rr>o2){
                res.append(1,s[seg_len*seg_num+o2]);
            }
        }
        for(int i=0;i<seg_num;i++){
            res.append(1,s[i*seg_len+nRows-1]);
        }
        if(rr>nRows-1){
            res.append(1,s[seg_num*seg_len+nRows-1]);
        }
        return res;
    }
};