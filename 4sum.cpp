class Solution {
public:
    void threeSum(vector<int>::iterator ost,vector<int>::iterator oed,vector<vector<int>>& rres,int prefix,int target) {
        int size = oed - ost;
        if(size<3){
            return;
        }
       int last = *ost;
        for(auto i=ost;i<oed-2;i++){
            if(i!=ost&&*i==last){
                continue;
            }
            last = *i;
            auto st = i+1;
            auto ed = oed-1;
            int neg = target-last;
            if(2**st>neg){
                break;
            }
            while(st<ed){
                if(2**st>neg){
                    break;
                }
                if(2**ed<neg){
                    break;
                }
                if(*st+*ed==neg){
                    vector<int> tp{prefix,*i,*st,*ed};
                    if(rres.empty()||rres.back()!=tp){
                        rres.push_back(tp);
                    }
                    st++;
                    ed--;
                }else if(*st+*ed<neg){
                    st = lower_bound(st+1,ed+1,neg-*ed);
                }else{
                    ed = upper_bound(st,ed-1,neg-*st);
                }
            }
        }
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        int size = num.size();
        if(size<4){
            return res;
        }
        sort(num.begin(),num.end());
        int last = num[0];
        for(int i=0;i<size-3;i++){
            if(i&&num[i]==last){
                continue;
            }
            last = num[i];
            threeSum(num.begin()+i+1,num.end(),res,last,target-last);
        }
        return res;
        
    }
};