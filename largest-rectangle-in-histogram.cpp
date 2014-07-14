class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int size = height.size();
        if(size==0){
            return 0;
        }
        if(size==1){
            return height[0];
        }
        int g_max = height[0];
        map<int,int> dict;//height -> index
        dict[height[0]]=0;
       for(int i=1;i<size;i++){
            int h = height[i];
            auto uit = dict.upper_bound(h);
            if(uit==dict.end()){
                if(dict.find(h)==dict.end()){
                    dict[h]=i;
                }
            }else{
                int uk = uit->first;
                int uv = uit->second;
                if(dict.find(h)==dict.end()){
                    dict[h]=uv;
                }
                dict.erase(uit,dict.end());
            }
            if(i!=size-1&&height[i]<height[i+1]){
                continue;
            }
            int local_max = 0;
            for(auto it=dict.begin();it!=dict.end();it++){
                //cout<<i<<" "<<it->first<<" "<<it->second<<" "<<(i-it->second+1)<<endl;
                int area = it->first*(i-it->second+1);
                if(area>g_max){
                    g_max = area;
                }
            }
        }
        return g_max;
    }
};