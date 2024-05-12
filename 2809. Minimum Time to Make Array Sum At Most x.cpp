class Solution {
public:
    int minimumTime(vector<int>& a, vector<int>& b, int x) {
        vector<pair<int, int>> s;
        int inc = 0, tot = 0, n = a.size();
        for (int i=0; i<n; ++i) {
            s.push_back({a[i], b[i]});
            inc += b[i];
            tot += a[i];
        }
        if (tot <= x) {
            return 0;
        }
        sort(s.begin(), s.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.second < b.second;
        });
        vector<vector<int>> f(n+1, vector<int>(n+1)); // max removal
        for (int i=0; i<n; ++i) {  // first (i+1) seconds, remove (i+1) elements
            for (int j=0; j<n; ++j) {  // removed elements are among [0..j]
                int f_keep_j = j == 0? 0 : f[i][j-1];
                int f_rmv_j = (i>0 && j>0) ? f[i-1][j-1] : 0;
                f[i][j] = max(f_keep_j, f_rmv_j+s[j].first+(i+1)*s[j].second);
            }
            if (tot + inc*(i+1) - f[i][n-1] <= x) {
                return (i+1);
            }
        }
        return -1;
    }
};