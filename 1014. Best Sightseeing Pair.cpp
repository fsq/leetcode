class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int ans = INT_MIN, mx = a[0] + 0;
        for (int i=1; i<a.size(); ++i) {
            ans = max(ans, a[i]-i+mx);
            mx = max(mx, a[i] + i);
        }
        return ans;
    }
};