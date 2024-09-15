class Solution {
public:
    long long maxSpending(vector<vector<int>>& a) {
        long long ans = 0;
        for (long long t=1, n=a.size()*a[0].size(); t<=n; ++t) {
            int mn = INT_MAX, mi = -1;
            for (int i=0; i<a.size(); ++i)
                if (a[i].size() && a[i].back()<mn) {
                    mn = a[i].back();
                    mi = i;
                }
            ans += t * mn;
            a[mi].pop_back();
        }
        return ans;
    }
};