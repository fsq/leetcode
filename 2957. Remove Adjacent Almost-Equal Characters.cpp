class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        // DP
        // vector<vector<int>> f(s.size(), vector<int>(26));
        // for (int i=0; i<26; ++i)
        //     f[0][i] = (s[0]=='a'+i) ? 0 : 1;
        
        // for (int i=1; i<s.size(); ++i)
        //     for (int a=0; a<26; ++a) {
        //         f[i][a] = INT_MAX;
        //         for (int b=0; b<26; ++b)
        //             if (abs(a-b)>1 && f[i-1][b]!=INT_MAX) {
        //                 f[i][a] = min(f[i][a], f[i-1][b]+(a+'a' != s[i]));
        //             }
        //     }

        // return *min_element(f.back().begin(), f.back().end());

        int i = 0, ans = 0;
        while (i+1<s.size()) {
            if (abs(s[i]-s[i+1]) <= 1) {
                ++ans;
                i += 2;
            } else {
                ++i;
            }
        }
        return ans;
    }
};