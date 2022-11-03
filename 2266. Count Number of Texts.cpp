class Solution {
public:
    
    const int M = 1000000007;
    
    int countTexts(string s) {
        vector<long long> f(s.size());
        f[0] = 1;
        for (int i=1; i<s.size(); ++i) {
            int mx = s[i]=='7' || s[i]=='9' ? 4 : 3;
            for (int j=i; j>=max(0, i-mx+1) && s[i]==s[j]; --j)
                f[i] = (f[i] + (j==0 ? 1 : f[j-1])) % M;
        }
        return f.back();
    }
};