class Solution {
public:
    int minWastedSpace(vector<int>& a, vector<vector<int>>& boxes) {
        long long ans = LLONG_MAX;
        sort(a.begin(), a.end());
        long long s = accumulate(a.begin(), a.end(), 0ll);
        
        for (auto& b : boxes) {
            sort(b.begin(), b.end());
            if (b.back() < a.back()) continue;
            long long sum = 0, pre = 0;
            for (long long x : b) {
                int i = upper_bound(a.begin()+pre, a.end(), x) - a.begin() - 1;
                if (i >= 0) {
                    sum += x * (i-pre+1);
                }
                pre = i + 1;
                if (pre == a.size()) break;
            }
            ans = min(ans, sum-s);
        }
        if (ans == LLONG_MAX) return -1;
        return ans % 1000000007;
    }
};