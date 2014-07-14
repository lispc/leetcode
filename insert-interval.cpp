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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
       
        vector<Interval> res;
         if(intervals.size()==0)
         {
             res.push_back(newInterval);
             return res;
         }
        auto i = begin(intervals);
        while(i<end(intervals)&&i->end<newInterval.start)
        {
            res.push_back(*i);
            i++;
        }
        auto t=i;
        while(t<end(intervals)&&t->start<=newInterval.end)
            t++;
        int s = (i!=end(intervals)&&i->start<newInterval.start)?i->start:newInterval.start;
        int e;
        if(t!=begin(intervals))
        {
            auto p = t-1;
            e = p->end>newInterval.end?p->end:newInterval.end;
        }
        else
            e = newInterval.end;
        res.push_back(Interval(s,e));
        res.insert(res.end(),t,end(intervals));
        
    }
};