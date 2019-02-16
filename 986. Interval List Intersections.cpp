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
    vector<Interval> intervalIntersection(vector<Interval>& a, vector<Interval>& b) {
        int i=0, j=0;
        vector<Interval> ans;
        while (i<a.size() && j<b.size()) {
            int l = max(a[i].start, b[j].start), r = min(a[i].end, b[j].end);
            if (r>=l)
                ans.emplace_back(l, r);
            if (a[i].end<b[j].end)
                ++i;
            else 
                ++j;
        }
        return ans;
    }
};