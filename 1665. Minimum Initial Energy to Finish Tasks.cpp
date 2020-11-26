class Solution {
public:
    // ans - (a[0]+...+a[j-1]) >= b[j], forall j
    // ==> ans >= a[0]+...+a[j-1] + b[j], forall j
    // Consider last j, ans >= Sum(a) - a[n-1] + b[n-1]
    // So we need to minimize (b[n-1]-a[n-1])
    // Recursively applies to all pairs.
    int minimumEffort(vector<vector<int>>& t) {
        sort(t.begin(), t.end(), [](vector<int>& a, vector<int>& b) {
            return a[1]-a[0] > b[1]-b[0];
        });
        int s = 0, ans = 0;
        for (int i=0; i<t.size(); ++i) {
            ans = max(ans, s + t[i][1]);
            s += t[i][0];
        }
        return ans;
    }
};