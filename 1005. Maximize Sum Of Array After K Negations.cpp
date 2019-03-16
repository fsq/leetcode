class Solution {
public:
    int largestSumAfterKNegations(vector<int>& a, int k) {
        int minabs = INT_MAX, ans=0;
        sort(a.begin(), a.end());
        for (auto& x : a) {
            minabs = min(minabs, abs(x));
            if (k && x<0) {
                x = -x;
                --k;
            }
            ans += x;
        }
        if (k & 1)
            ans -= 2 * minabs;
        return ans;
    }
};