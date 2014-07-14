class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        string sbuf;
        int size = words.size();
        int last = 0;
        int cl = 0;
        for(int i=0;i<size;i++){
            int ll = words[i].size();
            if(cl+ll+(i-last)>L){
                int space_num = L-cl;
                int slot_num = i-last-1;
                cl=0;
                if(slot_num==0){
                    sbuf.append(words[last++]);
                    sbuf.append(space_num,' ');
                }else{
                    int lb = space_num/slot_num;//5 3 2 2 1
                    int ub = lb+1;
                    int ub_num = space_num%slot_num;
                    sbuf.append(words[last++]);
                    for(int j=0;j<slot_num;j++){
                        int sl = (j<ub_num)?ub:lb;
                        sbuf.append(sl,' ');
                        sbuf.append(words[last++]);
                    }
                }
                res.push_back(sbuf);
                sbuf.clear();
            }
            cl+=ll;
        }
        for(int i=last;i<size;i++){
            if(i!=last){
                sbuf.append(" ");       
            }
            sbuf.append(words[i]);
        }
        sbuf.append(L-sbuf.size(),' ');
        res.push_back(sbuf);
        return res;
    }
};