class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        for (auto& s : words) ++m[s];
        int ans = 0, odd = 0;
        for (auto& pr : m) {
            auto& s = pr.first;
            if (s[0] == s[1]) {
                int match = pr.second / 2;
                ans += 4 * match;
                pr.second -= 2 * match;
                if (!odd && pr.second) {
                    odd = 1;
                    ans += 2;
                }
            } else {
                string t = s;
                swap(t[0], t[1]);
                if (m.count(t)) {
                    int match = min(m[s], m[t]);
                    m[s] -= match;
                    m[t] -= match;
                    ans += 4 * match;
                }
            }
        }
        return ans;
    }
};