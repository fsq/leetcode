class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size(), ans = INT_MIN;
        vector<int> l(n), r(n);
        l[0] = a[0];
        for (int i=1; i<n; ++i) 
            l[i] = max(l[i-1]+a[i], a[i]);
        r[n-1] = a[n-1];
        for (int i=n-2; i>=0; --i)
            r[i] = max(r[i+1]+a[i], a[i]);
        ans = max(*max_element(l.begin(),l.end()), *max_element(r.begin(), r.end()));
        for (int i=1; i+1<n; ++i)
            ans = max(ans, l[i-1]+r[i+1]);
        return ans;
    }
};