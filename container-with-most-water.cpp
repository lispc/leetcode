class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        if(size<=1){
            return 0;
        }
        if(size==2){
            return min(height[1],height[0]);
        }
        vector<pair<int,int>> bp;
        bp.push_back(make_pair(size-1,height.back()));
        for(int i=size-2;i>=0;i--){
            int v = height[i];
            if(v>bp.back().second){
                bp.push_back(make_pair(i,v));
            }
        }
        vector<pair<int,int>> fp;
        fp.push_back(make_pair(0,height[0]));
        for(int i=1;i<size;i++){
            int v = height[i];
            if(v>fp.back().second){
                fp.push_back(make_pair(i,v));
            }
        }
        int gmax = 0;
        for(int i=0;i<fp.size();i++){
            for(int j=0;j<bp.size();j++){
                int fx = fp[i].first;
                int fy = fp[i].second;
                int bx = bp[j].first;
                int by = bp[j].second;
                if(fx>=bx){
                    break;
                }
                int na = min(fy,by)*(bx-fx);
                if(na>gmax){
                    gmax = na;
                }
            }
        }
        return gmax;
    }
};