class Solution {
public:
    long long maximumTotalDamage(vector<int>& a) {
        unordered_map<int, long long> m;
        for (auto x : a) m[x] += x;
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(),a.end()) - a.begin());
        vector<long long> f(a.size());
        for (int i=0; i<a.size(); ++i) {
            if (i>0) f[i] = f[i-1];
            int j = i;
            while (j>=0 && a[j]>=a[i]-2) --j;
            f[i] = max(f[i], m[a[i]] + (j>=0 ? f[j] : 0));
        }
        return f.back();
    }
};