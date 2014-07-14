/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if(intervals.size()==0){
            return res;
        }
        sort(intervals.begin(),intervals.end(),[](const Interval& a,const Interval& b)->bool{return a.start<b.start;});
        int s = intervals[0].start;
        int e = intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            int is = intervals[i].start;
            int ie = intervals[i].end;
            if(is<=e){
                e = max(e,ie);
                continue;
            }else{
                res.push_back(Interval(s,e));
                s = is;
                e = ie;
            }
        }
        res.push_back(Interval(s,e));
        return res;
        
    }
};