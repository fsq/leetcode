class Solution {
public:
    int minSizeSubarray(vector<int>& a, int target) {
        long long t = accumulate(a.begin(), a.end(), 0ll);
        unordered_map<long long, int> m;
        m[0] = -1;
        long long cur = 0;
        int ans = INT_MAX;
        for (int i=0; i<a.size(); ++i) {
            cur += a[i];
            m[cur] = i;
        }
        cur = 0;
        for (int i=0; i<a.size(); ++i) {
            cur += a[i];
            auto x = ((cur - target)%t + t) % t;
            if (m.count(x)) {
                int k = (target + x - cur) / t;
                ans = min<int>(ans, k*a.size() + (i+1) - (m[x]+1));
            }
        }
        return ans == INT_MAX? -1 : ans;
    }
};