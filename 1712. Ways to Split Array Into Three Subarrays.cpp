class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int waysToSplit(vector<int>& s) {
        partial_sum(s.begin(), s.end(), s.begin());
        int ans = 0;
        for (int l=0, m=0, r=0; m+1<s.size(); ++l) {
            m = max(l+1, m);
            while (m<s.size() && s[m]-s[l]<s[l]) ++m;

            r = max(l+1, r);
            while (r+1<s.size() && (s.back()-s[r] >= s[r]-s[l])) ++r;

            if (r > m) {
                ans = (ans + r - m) % M;
            }
        }
        return ans;
    }
};