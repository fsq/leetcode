class Solution {
public:
    int waysToSplitArray(vector<int>& a) {
        int n = a.size();
        long long s = accumulate(a.begin(), a.end(), 0ll), t = 0;
        int ans = 0;
        for (int i=0; i<n-1; ++i) {
            t += a[i];
            if (t >= s - t) ++ans;
        }
        return ans;
    }
};