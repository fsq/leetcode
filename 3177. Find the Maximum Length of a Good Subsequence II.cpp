class Solution {
public:
    int maximumLength(vector<int>& a, int k) {
        // f[i][x] = max(f[i][x]+1, f[i-1][all y]+1);
        vector<unordered_map<int, int>> f(k+1);
        unordered_map<int, int> mx;
        for (auto x : a) {
            for (int i=k; i>=0; --i) {
                f[i][x] = max(f[i][x]+1, i>0 ? (mx[i-1]+1) : 0);
                mx[i] = max(mx[i], f[i][x]);
            }
        }
        return mx[k];
    }
};