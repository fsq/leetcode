class Solution {
public:

    int f(vector<int>& a, int k) {
        int ans = 1, i = 0, j = 0;
        for (i=0; i<a.size(); ) {
            for (j=i+1; j<a.size() && a[j]-a[i]<k; ++j);
            if (j<a.size()) {
                ++ans;
            }
            i = j;
        }
        return ans;
    }

    int maximumTastiness(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        if (a.size()<k) return 0;
        int l = 0, r = 1000000000;
        while (l < r) {
            int mid = (l+r+1) >> 1;
            if (f(a, mid) >= k)
                l = mid;
            else 
                r = mid - 1;
        }
        return l;
    }
};