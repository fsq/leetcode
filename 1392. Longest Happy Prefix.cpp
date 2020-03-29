class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> p(n);
        for (int i=1; i<n; ++i) {
            int j = p[i-1];
            while (j>0 && s[j]!=s[i]) j=p[j-1];
            p[i] = j + (s[j]==s[i]);
        }
        return s.substr(0, p.back());
    }
};