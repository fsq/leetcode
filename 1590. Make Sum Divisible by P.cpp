class Solution {
public:
    int minSubarray(vector<int>& a, int p) {
        long long sum = accumulate(a.begin(), a.end(), 0ll);
        long long rs = sum % p;
        if (rs == 0) return 0;
        unordered_map<int, int> b;
        b[0] = -1;
        long long s = 0;
        int ans = INT_MAX;
        for (int i=0; i<a.size(); ++i) {
            s += a[i];
            long long r = s % p;
            if (b.count((r - rs + p) % p)) 
                ans = min(ans, i - b[(r - rs + p) % p]);
            b[s % p] = i;
        }
        return ans == INT_MAX || ans == a.size() ? -1 : ans;
    }
};