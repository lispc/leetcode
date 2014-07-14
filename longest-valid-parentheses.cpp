class Solution {
public:
    int longestValidParentheses(string s) {
        vector<pair<int,int>> pairs;
        int l = s.size();
        if(l<=1){
            return 0;
        }
        stack<int> sk;//loc
        pair<int,int> cur_pair;
        int res = 0;
        for(int i=0;i<l;i++){
            char c = s[i];
            if(c=='('){
                sk.push(i);
                continue;
            }else{
                if(!sk.empty()){
                    int v = sk.top();
                    sk.pop();
                    auto p = make_pair(v,i+1);//[)
                    if(pairs.empty()){
                        pairs.push_back(p);
                        continue;
                    }
                    if(pairs.back().first>v){
                        pairs.pop_back();
                    }
                    if(pairs.back().second==v){
                        pairs.back()=make_pair(pairs.back().first,i+1);
                    }else {
                        pairs.push_back(p);
                    }
                }
            }
        }
        for(auto item:pairs){
            if(item.second-item.first>res){
                res = item.second-item.first;
            }   
        }
        return res;
    }
};