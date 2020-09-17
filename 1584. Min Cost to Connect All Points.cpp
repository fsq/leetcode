class Solution {
public:
    
    int dist(vector<int>& a, vector<int>& b) {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        vector<int> d(n, INT_MAX);
        d[0] = 0;
        for (int _t=0; _t<n; ++_t) {
            int mind = INT_MAX, p = 0;
            for (int i=0; i<n; ++i)
                if (d[i]!=-1 && d[i] < mind) {
                    mind = d[i];
                    p = i;
                }
            ans += mind;
            d[p] = -1;
            for (int j=0; j<n; ++j)
                if (d[j] != -1)
                    d[j] = min(d[j], dist(a[p], a[j]));
        }
        return ans;
    }
};