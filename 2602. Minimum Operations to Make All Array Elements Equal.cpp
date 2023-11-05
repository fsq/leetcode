class Solution {
public:
    vector<long long> minOperations(vector<int>& a, vector<int>& q) {
        long long n = a.size();
        sort(a.begin(), a.end());
        vector<long long> pre(n);
        pre[0] = a[0];
        for (int i=1; i<n; ++i) pre[i] = pre[i-1]+a[i];

        vector<long long> ans;
        for (long long x : q) {
            auto i = lower_bound(a.begin(), a.end(), x) - a.begin();
            long long ls = i==0 ? 0 : pre[i-1];
            long long bg = pre.back() - ls;
            ans.push_back((bg-(n-i)*x) + (i*x-ls));
        }
        return ans;
    }
};