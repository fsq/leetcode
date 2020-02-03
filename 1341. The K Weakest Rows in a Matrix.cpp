class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& a, int k) {
        int n = a.size();
        vector<int> s(n), p(n);
        iota(p.begin(), p.end(), 0);
        for (int i=0; i<n; ++i) s[i] = accumulate(a[i].begin(), a[i].end(), 0);
        sort(p.begin(), p.end(), [&](int x, int y) {
            return s[x] < s[y] || s[x]==s[y] && x<y; 
        });
        p.resize(k);
        return p;
    }
};