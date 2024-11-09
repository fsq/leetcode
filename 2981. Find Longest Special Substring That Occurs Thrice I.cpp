class Solution {
public:
    int sg[51][51];
    bool ok(string& s, int l) {
        unordered_map<string, int> cnt;
        for (int i=0; i+l<=s.size(); ++i)
            if (sg[i][i+l-1] && ++cnt[s.substr(i, l)] == 3) {
                // cout << s.substr(i, l) << endl;
                return true;
            }
        return false;
    }

    int maximumLength(string s) {
        memset(sg, 0, sizeof(sg));
        for (int i=0; i<s.size(); ++i) {
            unordered_set<char> st;
            for (int j=i; j<s.size(); ++j) {
                st.insert(s[j]);
                if (st.size() == 1) {
                    sg[i][j] = true;
                } else {
                    break;
                }
            }
        }
        int l=1, r=s.size();
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (ok(s, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return ok(s, l) ? l : -1;
    }
};