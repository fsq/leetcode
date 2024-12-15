class Solution {
public:
    long long maximumSubarraySum(vector<int>& a, int k) {
        vector<long long> s(a.size()+1);
        s[0] = 0;
        for (int i=0; i<a.size(); ++i) s[i+1] = s[i] + a[i];
        unordered_map<long long, long long> m;
        m[s[1]-s[0]] = s[0];
        long long ans = LLONG_MIN;
        for (int j=1; j<s.size(); ++j) {
            long long x = s[j] - s[j-1] + k;
            if (m.count(x)) {
                ans = max(ans, s[j] - m[x]);
            }
            x = s[j] - s[j-1] - k;
            if (m.count(x)) {
                ans = max(ans, s[j] - m[x]);
            }
            if (j+1<a.size()) {
                if (m.count(s[j+1]-s[j])) {
                    m[s[j+1]-s[j]] = min(m[s[j+1]-s[j]], s[j]);
                } else {
                    m[s[j+1]-s[j]] = s[j];
                }
            }
        }
        return ans==LLONG_MIN ? 0 : ans;
    }
};