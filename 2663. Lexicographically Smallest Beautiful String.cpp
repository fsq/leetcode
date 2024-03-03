class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        int change = -1;
        for (int i=n-1; i>=0; --i) {
            for (char c=s[i]+1; c<='a'+k-1; ++c) {
                if ((i-1<0 || c!=s[i-1]) && (i-2<0 || c!=s[i-2])) {
                    change = i;
                    s[i] = c;
                    break;
                }
            }
            if (change != -1) break;
        }

        if (change == -1) return "";
        for (int i=change+1; i<n; ++i) {
            for (int c='a'; c<'a'+k; ++c)
                if ((i-1<0 || c!=s[i-1]) && (i-2<0 || c!=s[i-2])) {
                    s[i] = c;
                    break;
                }
        }
        return s;
    }
};