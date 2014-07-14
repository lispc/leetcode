class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        //stringstream ssout;
        vector<string> vs;
        string seg;
        while(ss>>seg){
            vs.push_back(seg);
        }
        //copy(istream_iterator<string>(s),istream_iterator<string>(),back_inserter(vs));
        //copy(vs.rbegin(),vs.rend(),ostream_iterator<string>(ssout," "));
        s.clear();
        for(auto it=vs.rbegin();it!=vs.rend();it++){
            s.append(*it);
            s.append(1,' ');
        }
        s = s.substr(0,s.size()-1);
    }
};