class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        set<int> hashmap;
        int l = num.size();
        for(int i=0;i<l;i++){
            hashmap.insert(num[i]);
        }
        int maxV = 1;
        while(!hashmap.empty()){
            int v = *hashmap.begin();
            hashmap.erase(v);
            int len = 1;
            int index = v+1;
            while(hashmap.find(index)!=hashmap.end()){
                len++;
                hashmap.erase(index);
                index++;
            }
            index = v-1;
            while(hashmap.find(index)!=hashmap.end()){
                len++;
                hashmap.erase(index);
                index--;
            }
            if(len>maxV){
                maxV=len;
            }
        }
        return maxV;
    }
};