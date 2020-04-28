class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        k = a.size() - k;
        int now = accumulate(a.begin(), a.begin()+k, 0);
        int sum = accumulate(a.begin(), a.end(), 0);
        int ans = sum - now;
        for (int i=k; i<a.size(); ++i) {
            now = now + a[i] - a[i-k];
            ans = max(ans, sum-now);
        }
        return ans;
    }
};