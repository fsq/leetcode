class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& a) {
        for (auto& b : a) sort(b.rbegin(), b.rend());
        int ans = 0;
        for (int i=0; i<a[0].size(); ++i) {
            int m = INT_MIN;
            for (int j=0; j<a.size(); ++j) m = max(m, a[j][i]);
            ans += m;
        }
        return ans;
    }
};