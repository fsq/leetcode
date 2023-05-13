class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> a;
        int n = nums.size();
        long long l=0, r=0, cl=0, cr=0;
        for (int i=0; i<n; ++i) {
            r += cost[i];
            cr += (long long)nums[i] * cost[i];
            a.push_back({nums[i], cost[i]});
        }
        sort(a.begin(), a.end());

        long long ans = LLONG_MAX, pre = 0;
        for (int i=0; i<n; ++i) {
            long long x = a[i].first, c = a[i].second;
            cr = cr - (x-pre) * r;
            r -= c;
            cl = cl + (x-pre) * l;
            l += c;
            pre = x;
            ans = min(ans, cl + cr);
        }
        return ans;
    }
};