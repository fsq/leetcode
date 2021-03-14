class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int sa = accumulate(a.begin(), a.end(), 0);
        int sb = accumulate(b.begin(), b.end(), 0);
        if (sa > sb) {
            a.swap(b);
            swap(sa, sb);
        }
        vector<int> ca(7), cb=ca;
        for (auto x : a) ++ca[x];
        for (auto x : b) ++cb[x];
        int ans = 0;
        while (sa < sb) {
            int i, j;
            for (i=1; i<=6; ++i) if (ca[i]) break;
            for (j=6; j>=1; --j) if (cb[j]) break;
            if (i==6 && j==1) return -1;
            
            int inc = 6 - i, dec = j - 1, use = 0;
            if (inc > dec) {
                use = min(ca[i], (sb-sa+inc-1)/inc);
                sa += use * inc;
                ca[i] -= use;
                ca[6] += use;
            } else {
                use = min(cb[j], (sb-sa+dec-1)/dec);
                sb -= use * dec;
                cb[j] -= use;
                cb[1] += use;
            }
            ans += use;
        }
        return ans;
    }
};