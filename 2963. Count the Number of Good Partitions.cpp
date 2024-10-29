class Solution {
public:
    const int M = 1000000007;
    int numberOfGoodPartitions(vector<int>& a) {
        unordered_map<int, int> rt;
        int n = a.size(), seg = 0;
        for (int i=0; i<n; ++i) rt[a[i]] = i;
        for (int l=0; l<n; ) {
            int r = rt[a[l]], i = l;
            while (i < r) {
                r = max(r, rt[a[i]]);
                ++i;
            }
            l = r + 1;
            ++seg;
        }
        int ans = 1;
        for (int i=1; i<seg; ++i) ans = (ans * 2) % M;
        return ans;
    }
};