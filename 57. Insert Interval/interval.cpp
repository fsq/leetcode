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
    
    // https://leetcode.com/problems/insert-interval/description/
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        bool pushed = false;
        for (auto& itv : intervals) 
            if (itv.start>newInterval.end) {
                if (!pushed) {
                    ret.push_back(newInterval);
                    pushed = true;
                } 
                ret.push_back(itv);  
            } else if (itv.end<newInterval.start)
                ret.push_back(itv);
            else {
                newInterval.start = min(newInterval.start, itv.start);
                newInterval.end = max(newInterval.end, itv.end);
            }
        if (!pushed)
            ret.push_back(newInterval);
        return ret;
    }
};