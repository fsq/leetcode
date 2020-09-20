class Solution {
public:
    int maxSumRangeQuery(vector<int>& a, vector<vector<int>>& requests) {
        int n = a.size();
        vector<int> s(n+1), cnt(n);
        for (auto& r : requests) {
            ++s[r[0]];
            --s[r[1] + 1];
        }
        for (int c=0, i=0; i<n; ++i) {
            c += s[i];
            cnt[i] = c;
        }
        sort(cnt.begin(), cnt.end(), std::greater<int>());
        sort(a.begin(), a.end(), std::greater<int>());
        long long ans = 0;
        for (int i=0; i<n; ++i)
            ans = (ans + a[i] * cnt[i]) % 1000000007;
        return ans;
    }
};