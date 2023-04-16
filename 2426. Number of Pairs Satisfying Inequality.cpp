class Solution {
public:
    vector<int> s;

    int lowbit(int x) { return x & (-x); }

    void inc(int x) {
        for (; x<s.size(); x+=lowbit(x)) ++s[x];
    }

    int count(int x) {
        int ans = 0;
        for (; x>0; x-=lowbit(x)) ans += s[x];
        return ans;
    }

    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        int mn=INT_MAX, mx=INT_MIN;
        // nums1i-nums2i<=nums1j-nums2j+diff
        for (int i=0; i<a.size(); ++i) {
            a[i]-=b[i];
            mn = min(a[i], mn);
            mx = max(a[i], mx);
        }
        s.resize(mx-mn+2); // 1..mx-mn+1, 0 is un-used
        long long ans = 0;
        for (int i=0; i<a.size(); ++i) {
            ans += count(max(min(a[i]+diff, mx),mn-1)-mn+1);
            inc(a[i]-mn+1);
        }
        return ans;
    }
};