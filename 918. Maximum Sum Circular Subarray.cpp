class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int ans = INT_MIN;
        
        if (all_of(a.begin(), a.end(), [](int x){ return x<=0; }))
            return *max_element(a.begin(), a.end());
        
        int tot = accumulate(a.begin(), a.end(), 0);
        
        int mx=0, mn=0;
        for (auto x : a) {
            mx = max(mx+x, x);
            mn = min(mn+x, x);
            ans = max(ans, max(mx, tot-mn));
        }
        
        return ans;
    }
};