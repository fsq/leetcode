class Solution {
public:
    int edgeScore(vector<int>& e) {
        int n = e.size();
        vector<long long> f(n);
        for (int i=0; i<n; ++i)
            f[e[i]] += i;
        int ans=0;
        long long mx = 0;
        for (int i=0; i<n; ++i)
            if (f[i] > mx) {
                mx = f[i];
                ans = i;
            }
        return ans;
    }
};