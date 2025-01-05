class Solution {
public:

    bool ok(vector<vector<int>>& a, int l) {
        for (int i=l; i<a.size(); i+=l) {
            for (int c=0; c<26; ++c)
                if (a[i][c]-a[i-l][c] != a[l][c]) return false;
        }
        return true;
    }

    int minAnagramLength(string s) {
        vector<vector<int>> cnt(s.size()+1, vector<int>(26));
        for (int i=0; i<s.size(); ++i) {
            cnt[i+1] = cnt[i];
            ++cnt[i+1][s[i]-'a'];
        }
        for (int l=1; l<=s.size()/2; ++l)
            if (s.size() % l == 0) {
                if (ok(cnt, l)) return l;
            }
        return s.size();
    }
};