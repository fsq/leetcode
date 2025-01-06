class Solution {
public:

    bool balanced(vector<int>& cnt) {
        int c = -1;
        for (auto x : cnt) {
            if (x == 0) continue;
            if (c == -1)
                c = x;
            else if (c != x)
                return false;
        }
        return true;
    }

    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> f(n, INT_MAX);
        f[0] = 1;
        for (int i=1; i<s.size(); ++i) {
            vector<int> cnt(26);
            for (int j=i; j>=0; --j) {
                ++cnt[s[j]-'a'];
                if (balanced(cnt)) {
                    f[i] = min(f[i], (j==0 ? 0 : f[j-1]) + 1);
                }
            }
        }
        return f[n-1];
    }
};