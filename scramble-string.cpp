class Solution {
public:
    map<pair<string,string>,bool> cache;
    bool isScramble(string s1, string s2,int rev=1) {
        int l = s1.size();
        if(l==0){
            return true;
        }
        if(l==1){
            return s1[0]==s2[0];
        }
        if(l==2){
            return s1[0]==s2[0]&&s1[1]==s2[1]||s1[0]==s2[1]&&s1[1]==s2[0];
        }
        if(cache.find(make_pair(s1,s2))!=cache.end()){
            return cache[make_pair(s1,s2)];
        }
        int f1[256];
        int f2[256];
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        for(int i=0;i<l;i++){
            f1[s1[i]]++;
            f2[s2[i]]++;
        }
        if(memcmp(f1,f2,sizeof(f1))){
             cache[make_pair(s1,s2)]=false;
            return false;
        }
        int hash1 = s1[0];
        int hash2 = s2[0];
        for(int i=1;i<l;i++){
            if(hash1==hash2){
                if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i))){
                     cache[make_pair(s1,s2)]=true;
                    return true;
                }
            }
            hash1 ^= s1[i];
            hash2 ^= s2[i];
        }
        if(rev){
            if(isScramble(s1,string(s2.rbegin(),s2.rend()),0)){
                 cache[make_pair(s1,s2)]=true;
                return true;
            }
        }
         cache[make_pair(s1,s2)]=false;
        return false;
        
    }
};