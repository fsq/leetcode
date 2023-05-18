class Solution {
public:
    int destroyTargets(vector<int>& a, int space) {
        unordered_map<int, int> m, min_elem;
        for (auto x : a) {
            int& c = min_elem[x % space];
            c = c==0 ? x : min(c, x);
        }
        int mx = 0, ans = 0;
        for (auto x : a) {
            int& c = m[x % space];
            ++c;
            if (c > mx || (c==mx && min_elem[x%space]<ans)) {
                mx = c;
                ans = min_elem[x % space];
            }
        }
        return ans;
    }
};