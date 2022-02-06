class Solution {
public:
    int waysToPartition(vector<int>& a, int k) {
        long long tot = accumulate(a.begin(), a.end(), 0ll);
        int ans = 0;
        unordered_map<int, int> l, r;
        for (long long i=0, s=0; i+1<a.size(); ++i) {
            s += a[i];
            if (s * 2 == tot) ++ans;
            ++r[s];
        }

        for (long long s=0, i=0; i<a.size(); ++i) {
            auto new_tot = tot - a[i] + k;
            if (! (new_tot&1)) {
                // prefix_sum-a[i]+k==new_tot/2
                int cnt = l[new_tot / 2] + r[new_tot/2+a[i]-k];
                ans = max(ans, cnt);
            }
            s += a[i];
            --r[s];
            ++l[s];
        }
        return ans;
    }
};