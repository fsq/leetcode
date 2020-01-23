class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> mr(n+1);
        for (int i=0; i<=n; ++i) {
            int l = max(0, i-ranges[i]), r = min(n, i+ranges[i]);
            mr[l] = max(mr[l], r);
        }
        
        int r = 0, ans = 0;
        for (int j,i=0; i<=n && r<n; i=j) {
            int nr = -1;
            for (j=i; j<=r; ++j)
                nr = max(nr, mr[j]);
            if (nr==-1) return -1;
            r = nr;
            ++ans;
        }
        return r==n ? ans : -1;
    }
};