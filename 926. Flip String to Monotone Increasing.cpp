class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int n = s.size();
        
        int ans = min(ones, n-ones), cur = 0;
        
        for (int i=0; i<n; ++i) {
            cur += s[i]=='1';
            ans = min(ans, cur+(n-(i+1)-(ones-cur)));
        }
        return ans;
    }
};