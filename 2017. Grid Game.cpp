class Solution {
public:
    long long gridGame(vector<vector<int>>& a) {
        vector<vector<long long>> s(2, vector<long long>(a[0].size()));
        s[0][0] = a[0][0], s[1][0] = a[1][0];
        for (int i=1; i<a[0].size(); ++i) {
            s[0][i] = s[0][i-1] + a[0][i];
            s[1][i] = s[1][i-1] + a[1][i];
        }
        
        long long ans = LLONG_MAX;
        for (int i=0; i<a[0].size(); ++i) {
            ans = min(ans, max(s[0].back() - s[0][i], i==0 ? 0 : s[1][i-1]));
        }
        return ans;
    }
};