class Solution {
public:
    long long maxSum(vector<int>& a, int m, int k) {
        vector<long long> s(a.size());
        s[0] = a[0];
        for (int i=1; i<a.size(); ++i) s[i] = s[i-1] + a[i];
        unordered_map<int, int> c;
        int dist = 0;
        for (int i=0; i<k; ++i) {
            if (++c[a[i]] == 1)
                ++dist;
        }
        long long ans = dist >= m ? s[k-1] : 0;
        for (int i=k; i<a.size(); ++i) {
            if (++c[a[i]] == 1) ++dist;
            if (--c[a[i-k]] == 0) --dist;
            if (dist >= m) {
                ans = max(ans, s[i] - s[i-k]);
            }
        }
        return ans;
    }
};