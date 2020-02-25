class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> nxt(3, n);
        nxt[s.back()-'a'] = n - 1;
        int ans = 0;
        for (int i=n-2; i>=0; --i) {
            nxt[s[i]-'a'] = i;
            ans += n - *max_element(nxt.begin(), nxt.end());
        }
        return ans;
    }
};