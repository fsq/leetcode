class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        for (auto& comp : composition) {
            long long l=0, r=200000000;
            while (l < r) {
                auto mid = (l+r+1) >> 1;
                long long c = 0;
                for (int i=0; i<n; ++i) {
                    c += max(comp[i]*mid - stock[i], 0ll) * cost[i];
                }
                if (c > budget) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            ans = max<int>(ans, l);
        }
        return ans;
    }
};