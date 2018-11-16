class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        const int M = 1e9 + 7;
        vector<int> f(26);
        int sum, prev = 1;
        f[s[0]-'a'] = 1;
        for (int i=1; i<n; ++i) {
            sum = (prev-f[s[i]-'a']+M) % M;
            f[s[i]-'a'] = (prev+1) % M;
            sum = (sum+f[s[i]-'a']) % M;
            prev = sum;
        }
        return sum;
    }
};