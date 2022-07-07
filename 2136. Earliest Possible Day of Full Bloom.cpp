class Solution {
public:
    int earliestFullBloom(vector<int>& a, vector<int>& b) {
        vector<int> ind(a.size());
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](int x, int y) {
            return b[x] > b[y]; 
        });
        int ans = 0, s = 0;
        for (auto x : ind) {
            s += a[x];
            ans = max(ans, s + b[x]);
        }
        return ans;
    }
};