/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    struct K{
        int dy;
        int dx;
        K(){}
        K(int y,int x){
            if(x<0){
                dy = -y;
                dx = -x;
            }else{
                dy = y;
                dx = x;
            }
        }
        bool operator<(const K& b) const{
            return dy*b.dx<dx*b.dy;
        }
    };
    int maxPoints(vector<Point> &points) {
        int l = points.size();
        if(l<=2){
            return l;
        }
        sort(points.begin(),points.end(),[](const Point& a,const Point& b)->bool{
           return a.x<b.x||a.x==b.x&&a.y<b.y;
        });
        vector<int> cnt;
        vector<Point> uni;
        uni.push_back(points[0]);
        cnt.push_back(1);
        auto last = points[0];
        for(int i=1;i<l;i++){
            if(points[i].x==last.x&&points[i].y==last.y){
                cnt.back()++;
            }else{
                last = points[i];
                cnt.push_back(1);
                uni.push_back(points[i]);
            }
        }
        int real_len = uni.size();
        map<K,int> kf;
        int gmax = cnt[0];
        for(int i=0;i<real_len-1;i++){
            int vecnt = 0;
            for(int j=i+1;j<real_len;j++){
                int cc = cnt[j];
                int dx = uni[i].x - uni[j].x;
                int dy = uni[i].y - uni[j].y;
                if(dx==0){
                    vecnt+=cc;
                    continue;
                }
                K k(dx,dy);
                if(kf.find(k)!=kf.end()){
                    kf[k]+=cc;
                }else{
                    kf[k]=cc;
                }
            }
            int tmax = vecnt;
            for(auto it=kf.begin();it!=kf.end();it++){
                if(it->second>tmax){
                    tmax = it->second;
                }
            }
            if(tmax+cnt[i]>gmax){
                gmax = tmax+cnt[i];
            }
            kf.clear();
        }
        return gmax;
    }
};