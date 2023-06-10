class Solution {
public:
    const int M = 1000000007;

    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        // if s[i]!=prime, then f[i][k] = Sum f[j][k-1] where j<=i-minLength & s[j+1]=prime
        vector<vector<int>> f(n+1, vector<int>(k+1)), pre = f;
        unordered_set<char> prime = {'2','3','5','7'};
        f[0][0] = 1;
        pre[0][0] = 1;
        for (int i=minLength; i<=s.size(); ++i) {
            for (int p=0; p<=k; ++p) {
                pre[i-minLength][p] = i-minLength>0 ? pre[i-minLength-1][p] : 0;
                if (prime.count(s[i-minLength]))
                    pre[i-minLength][p] = (pre[i-minLength][p] + f[i-minLength][p]) % M;
            }
            if (prime.count(s[i-1]) == 0)
                for (int p=1; p<=min(k, i/minLength); ++p) {
                    f[i][p] = pre[i-minLength][p-1];
                }
        }
        return f[n][k];
    }
};