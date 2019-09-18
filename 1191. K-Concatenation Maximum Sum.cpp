class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int kConcatenationMaxSum(vector<int>& a, int k) {
        int ans = 0, tot = 0;
        for (int s=0,i=0; i<a.size(); ++i) {
            s = max(s+a[i], a[i]);
            ans = max(s, ans);
            tot += a[i];
        }
        
        if (k==1) return ans;
        
        vector<long long> l(a.size()), r=l;
        partial_sum(a.begin(), a.end(), l.begin());
        partial_sum(a.rbegin(), a.rend(), r.rbegin());
        long long f = max(0ll, *max_element(l.begin(), l.end())) + max(0ll, *max_element(r.begin(), r.end()));
        return max<int>(ans, (f+(k-2)*max<long long>(tot, 0))%M);
    }
};