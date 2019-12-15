class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intv) {
        int ans = 0;
        sort(intv.begin(), intv.end());
        int rt = -1;
        for (int i=0; i<intv.size(); ++i) 
            if (rt < intv[i][1]) {
                ++ans;
                rt = intv[i][1];
            }
        
        return ans;
    }
};