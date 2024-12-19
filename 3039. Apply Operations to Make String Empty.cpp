class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> cnt;
        int mx = 0;
        for (auto c : s)
            if (++cnt[c] > mx) {
                mx = cnt[c];
            }
        string ans;
        for (auto it=s.rbegin(); it!=s.rend(); ++it)
            if (cnt[*it] == mx) {
                ans.push_back(*it);
                cnt[*it] = -1;
            }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};