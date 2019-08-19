class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cnt(26);
        for (auto c : chars) ++cnt[c-'a'];
        int ans = 0;
        for (auto& s : words) {
            vector<int> a(26);
            for (auto c : s) ++a[c-'a'];
            bool ok = true;
            for (int i=0; i<26; ++i)
                if (a[i] > cnt[i]) {
                    ok = false;
                    break;
                }
            if (ok) ans += s.size();
        }
        return ans;
    }
};