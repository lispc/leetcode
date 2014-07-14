class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int ll = L[0].size();
        int lsize = L.size();
        unordered_map<string,int> kv;
        sort(L.begin(),L.end());
        vector<string> dedup = L;
        dedup.erase(unique(dedup.begin(),dedup.end()),dedup.end());
        int dsize = dedup.size();
        for(int i=0;i<dsize;i++){
            kv[dedup[i]]=i;
        }
        vector<int> cnt(dsize,0);
        for(int i=0;i<lsize;i++){
            cnt[kv[L[i]]]++;
        }
        int sl = S.size();
        vector<int> s2l(sl,-1);
        for(int i=0;i<=sl-ll;i++){
            string seg = S.substr(i,ll);
            if(kv.find(seg)!=kv.end()){
                s2l[i]=kv[seg];
            }
        }
        vector<int> res;
        for(int i=0;i<=sl-ll*lsize;i++){
            map<int,int> all;
            int j = i;
            while(s2l[j]!=-1&&j<i+lsize*ll){
                if(all.find(s2l[j])==all.end()){
                    all[s2l[j]]=1;
                }else{
                    all[s2l[j]]++;
                }
                if(all[s2l[j]]>cnt[s2l[j]]){
                    break;
                }
                j+=ll;
            }
            if(j==i+lsize*ll){
                res.push_back(i);
            }
        }
        return res;
    }
};