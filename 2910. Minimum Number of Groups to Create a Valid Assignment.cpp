class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& a) {
        unordered_map<int, int> m;
        for (auto x : a) ++m[x];
        int mf = INT_MAX;
        for (auto pr : m) mf = min(mf, pr.second);

        for (int h = mf; h >= 1; --h) { // smallest pile
            bool ok = true;
            int ans = 0;
            for (auto pr : m) {
                // Try to split into (h+1) first
                int a = pr.second / (h+1);
                int b = pr.second % (h+1);
                if (b == 0) {
                    ans += a;
                } else if (b==h || (b<h && (h-b)<=a)) {
                    ans += a + 1;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) return ans; 
        }
        return -1;
    }
};