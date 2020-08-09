class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) return false;
        int n = s.size();
        vector<int> d(26);
        for (int i=0; i<n; ++i) 
            ++d[(t[i]-s[i]+26) % 26];
        for (int i=1; i<26; ++i) {
            int x = d[i];
            int has = k / 26 + (int)(k%26 >= i);
            if (has < x) return false;
        }
        return true;
    }
};