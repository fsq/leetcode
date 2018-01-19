class Solution {
public:
    
    // https://leetcode.com/problems/valid-square/description/
    // O(1) solution
    // calculate the distances of all pairs of points
    // there must be four equally short edges and two equally long edges.
    // also sqrt(2)*short == long
    
    int dist(const vector<int>& a, const vector<int>& b) {
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> lens;
        lens.push_back(dist(p1, p2));
        lens.push_back(dist(p1, p3));
        lens.push_back(dist(p1, p4));
        lens.push_back(dist(p2, p3));
        lens.push_back(dist(p2, p4));
        lens.push_back(dist(p3, p4));
        
        auto pr = minmax_element(lens.begin(), lens.end());
        int cnt_short=0, cnt_long=0;
        for (auto x : lens)
            if (x==*pr.first) ++cnt_short;
            else if (x==*pr.second) ++cnt_long;
        
        if (cnt_short+cnt_long != 6) return false;
        if (cnt_short!=4) return false;
        if (*pr.first<<1 != *pr.second) return false;
        
        return true;
    }
};