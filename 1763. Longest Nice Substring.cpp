class Solution {
public:
    string longestNiceSubstring(string s) {
        for (int l=s.size(); l>=2; --l) {
            vector<int> cnt(128);
            for (int i=0; i+1<l; ++i)
                ++cnt[s[i]];
            for (int i=l-1; i<s.size(); ++i) {
                ++cnt[s[i]];
                if (i>=l) --cnt[s[i-l]];
                bool ok = true;
                for (int i=0; i<26; ++i)
                    if (!(cnt['A'+i] && cnt['a'+i] || cnt['A'+i]==0 && cnt['a'+i]==0)) {
                        ok = false;
                        break;
                    }
                if (ok) return s.substr(i-l+1, l);
            }
        }
        return "";
    }
};