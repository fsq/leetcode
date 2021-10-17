class Solution {
public:
    
    const long long b = 100001;
    const long long m = 100000000019;
    
    void hash(vector<int>& a, unordered_set<long long>& st, int len, bool first) {
        long long t = 1, h = a[0];
        for (int i=1; i<len; ++i) {
            h = (h * b + a[i]) % m;
            t = (t * b) % m;
        }
        unordered_set<long long> cur;
        if (first || st.count(h))
            cur.insert(h);
        for (int i=len; i<a.size(); ++i) {
            h = (h - a[i-len]*t% m + m) % m;
            h = (h * b + a[i]) % m;
            if (first || st.count(h)) cur.insert(h);
        }
        st = cur;
    }
    
    
    int longestCommonSubpath(int n, vector<vector<int>>& p) {
        int l=0, r=INT_MAX;
        for (auto& sp : p) r = min<int>(r, sp.size());
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            unordered_set<long long> st;
            hash(p[0], st, mid, true);
            for (int i=1; i<p.size() && st.size(); ++i) {
                hash(p[i], st, mid, false);
            }
            if (st.size()) 
                l = mid;
            else 
                r = mid - 1;
        }
        return l;
    }
};