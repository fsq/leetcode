class Solution {
public:
    
    inline int lowbit(int x) {
        return x & (-x);
    }
    
    void add(vector<int>& s, int i, int delta) {
        for (++i; i<s.size(); i+=lowbit(i)) s[i] += delta;
    }
    
    long long count(vector<int>& s, int i) {
        long long ans = 0;
        for (++i; i>0; i-=lowbit(i)) ans += s[i];
        return ans;
    }
    
    long long goodTriplets(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> posb(n);
        for (int i=0; i<n; ++i) posb[b[i]] = i;
        vector<int> sl(n+1), sr=sl; // {b->a}
        for (int i=n-1; i>=0; --i)
            add(sr, posb[a[i]], 1);
        long long ans = 0;
        for (int i=0; i<n; ++i) {
            long long left = count(sl, posb[a[i]]-1);
            long long right = n - i - count(sr, posb[a[i]]);
            ans += left * right;
            add(sl, posb[a[i]], 1);
            add(sr, posb[a[i]], -1);
        }
        return ans;
    }
};
