class Solution {
public:
    int longestEqualSubarray(vector<int>& a, int k) {
        unordered_map<int, vector<int>> m;
        for (int i=0; i<a.size(); ++i) m[a[i]].push_back(i);
        int ans = 1;
        for (auto &[_x, a] : m) {
            for (int l=0, r=1, d=0; r<a.size(); ++r) {
                d += a[r] - a[r-1] - 1;
                while (d > k && l+1<=r) {
                    d -= a[l+1] - a[l] - 1;
                    ++l;
                }
                if (d <= k)
                    ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};