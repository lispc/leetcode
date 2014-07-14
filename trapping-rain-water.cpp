class Solution {
public:
    int trap(int A[], int n) {
        int res = 0;
        stack<pair<int,int>> asc;
        stack<pair<int,int>> desc;
        if(n<=2){
            return 0;
        }
        int raw_sum = 0;
        for(int i=0;i<n;i++){
            int v = A[i];
            raw_sum+=v;
            if(asc.empty()){
                asc.push(make_pair(v,1));
                //desc.push(make_pair(v,1));
                continue;
            }
            if(desc.empty()){
                if(v<asc.top().first){
                    desc.push(make_pair(v,1));
                }else if(v>asc.top().first){
                    asc.push(make_pair(v,1));
                }else{
                    asc.top().second++;
                }
                continue;
            }
            if(v<desc.top().first){
                desc.push(make_pair(v,1));
                continue;
            }
            if(v==desc.top().first){
                desc.top().second++;
                continue;
            }
            if(v>asc.top().first){
                int sm = 0;
                while(!desc.empty()){
                    sm+=desc.top().second;
                    desc.pop();
                }
                asc.top().second+=sm;
                asc.push(make_pair(v,1));
                continue;
            }
            if(v==asc.top().first){
                int sm = 0;
                while(!desc.empty()){
                    sm+=desc.top().second;
                    desc.pop();
                }
                asc.top().second+=sm;
                asc.top().second++;
                continue;
            }
            int nl = 0;
            while(!desc.empty()&&desc.top().first<v){
                int vv = desc.top().first;
                int ll = desc.top().second;
                desc.pop();
                nl+=ll;
            }
            if(desc.empty()){
                desc.push(make_pair(v,nl+1));
                continue;
            }
            if(desc.top().first==v){
                desc.top().second+=nl;
                desc.top().second++;
                continue;
            }
            desc.push(make_pair(v,nl+1));
        }
        while(!asc.empty()){
            res+=asc.top().first*asc.top().second;
            asc.pop();
        }
         while(!desc.empty()){
            res+=desc.top().first*desc.top().second;
            desc.pop();
        }
        return res-raw_sum;
        
    }
};