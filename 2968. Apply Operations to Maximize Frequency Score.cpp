class Solution {
public:

    long long cost(vector<int>& a, vector<long long>& s, int l, int r) {
        if (l == r) return 0;
        long long m = (l+r)>>1, l1=m-l+1, l2=r-l+1-l1;
        long long cost = a[m]*l1 - (s[m] - (l==0 ? 0 : s[l-1])) + (s[r] - s[m]) - a[m]*l2;
        return cost; 
    }

    int maxFrequencyScore(vector<int>& a, long long k) {
        sort(a.begin(), a.end());
        vector<long long> s(a.size());
        s[0] = a[0];
        for (int i=1; i<a.size(); ++i) s[i] = s[i-1] + a[i];
        int ans = 0;
        for (int l=0,r=0; l<a.size(); ++l) {
            while (r+1<a.size() && cost(a, s, l, r+1)<=k) ++r;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};