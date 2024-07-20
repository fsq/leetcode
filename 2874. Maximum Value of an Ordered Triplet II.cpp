class Solution {
public:
    long long maximumTripletValue(vector<int>& a) {
        int n = a.size();
        vector<long long> mnr(n), mxr(n);
        mnr[n-1] = mxr[n-1] = a[n-1];
        for (int i=n-2; i>=0; --i) {
            mnr[i] = min<long long>(mnr[i+1], a[i]);
            mxr[i] = max<long long>(mxr[i+1], a[i]);
        }
        long long mn=a[0], mx=a[0], ans=0;
        for (int i=1; i+1<n; ++i) {
            ans = max(ans, max((mx-a[i])*mnr[i+1], (mx-a[i])*mxr[i+1]));
            ans = max(ans, max((mn-a[i])*mnr[i+1], (mn-a[i])*mxr[i+1]));
            mn = min<long long>(mn, a[i]);
            mx = max<long long>(mx, a[i]);
        }
        return ans;
    }
};