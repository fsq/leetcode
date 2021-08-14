class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& rm) {
        int n = s.size();
        vector<vector<int>> next(n, vector<int>(26, n));
        next[n-1][s[n-1]-'a'] = n-1;
        for (int i=n-2; i>=0; --i) {
            next[i] = next[i+1];
            next[i][s[i]-'a'] = i;
        }
        int l=0, r=rm.size();
        while (l < r) {
            int mid = (l+r+1) >> 1;
            unordered_set<int> ind(rm.begin(), rm.begin()+mid);
            int i=0, j=0;
            while (i<s.size() && j<p.size()) 
                if (ind.count(i))
                    ++i;
                else if (s[i]==p[j]) {
                    ++i;
                    ++j;
                } else {
                    i = next[i][p[j]-'a'];
                }
            if (j==p.size()) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};