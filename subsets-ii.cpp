class Solution {
public:
    vector<vector<int>> rec(vector<pair<int,int>>::iterator st,vector<pair<int,int>>::iterator ed,vector<vector<int>> prefix){
        if(st==ed){
            return prefix;
        }
        int v = st->first;
        int f = st->second;
        vector<vector<int>> new_pre;
        for(vector<int> item:prefix){
            for(int i=0;i<=f;i++){
                vector<int> item_copy = item;
                item_copy.insert(item_copy.end(),i,v);
                new_pre.push_back(item_copy);
            }
        }
        return rec(st+1,ed,new_pre);
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> res(1,vector<int>());
        int l = S.size();
        if(!l){
            return res;
        }
        vector<pair<int,int>> freq;
        sort(S.begin(),S.end());
        int cur = S[0];
        int cnt = 1;
        for(int i=1;i<l;i++){
            int v = S[i];
            if(v==cur){
                cnt++;
            }else{
                freq.push_back(make_pair(cur,cnt));
                cnt = 1;
                cur = v;
            }
        }
        freq.push_back(make_pair(cur,cnt));
        return rec(freq.begin(),freq.end(),res);
        
    }
};