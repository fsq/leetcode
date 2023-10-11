class Solution {
public:
    const int M = 1000000007;
    int countWays(vector<vector<int>>& r) {
        map<int, int> m;
        for (auto& s : r) {
            ++m[s[0]], --m[s[1]];
        }
        int cur = 0, grp = 0, ans = 1;
        for (auto& pr : m) {
            cur += pr.second;
            if (cur==0) {
                ++grp;
                ans = (ans * 2) % M;
            }
        }
        return ans;
    }
};