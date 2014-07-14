class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(),num.end());
        if(num.size()<3){
            return res;
        }
       int last = num[0];
        for(int i=0;i<num.size()-2;i++){
            if(i&&num[i]==last){
                continue;
            }
            last = num[i];
            int st = i+1;
            int ed = num.size()-1;
            int neg = -num[i];
            if(2*num[st]>neg){
                break;
            }
            while(st<ed){
                if(2*num[st]>neg){
                    break;
                }
                if(2*num[ed]<neg){
                    break;
                }
                if(num[st]+num[ed]==neg){
                    vector<int> tp{num[i],num[st],num[ed]};
                    if(res.empty()||res.back()!=tp){
                        res.push_back(tp);
                    }
                    st++;
                    ed--;
                }else if(num[st]+num[ed]<neg){
                    auto res = lower_bound(num.begin()+st+1,num.begin()+ed+1,neg-num[ed]);
                    st = res - num.begin();
                }else{
                    auto res = upper_bound(num.begin()+st,num.begin()+ed-1,neg-num[st]);
                    ed = res - num.begin();
                }
            }
        }
        return res;
        
        
    }
};