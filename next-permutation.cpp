class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        if(size<=1){
            return;
        }
        int cur = size-2;
        while(cur>=0){
            if(num[cur]>=num[cur+1]){
                cur--;
                continue;
            }
            int v = num[cur];
            sort(num.begin()+cur,num.end());
            auto it = upper_bound(num.begin()+cur,num.end(),v);
            //auto vit = lower_bound(num.begin()+cur,num.end(),v);
            int new_head = *it;
            *it = num[cur];
            num[cur]=new_head;
            sort(num.begin()+cur+1,num.end());
            break;
        }
        if(cur<0){
            sort(num.begin(),num.end());
        }
    }
};