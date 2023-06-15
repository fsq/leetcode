class Solution {
public:
    const int M = 1000000007;

    int countPalindromes(string s) {
        int n = s.size();
        vector<vector<long long>> l(n+1, vector<long long>(100)), r = l;
        vector<int> c1(10), c2(10);
        ++c1[s[0]-'0'];
        ++c2[s[n-1]-'0'];
        for (int i=1; i<n; ++i) {
            l[i] = l[i-1];
            r[n-i-1] = r[n-i];
            for (int j=0; j<=9; ++j) {
                int x = j*10 + (s[i]-'0'), y = (s[n-i-1]-'0')*10 + j;
                l[i][x] = (l[i][x] + c1[j]) % M;
                r[n-i-1][y] = (r[n-i-1][y]+c2[j]) % M;
            }
            ++c1[s[i]-'0'];
            ++c2[s[n-i-1]-'0'];
        }
        int ans = 0;
        for (int i=2; i+2<n; ++i)
            for (int x=0; x<=9; ++x)
                for (int y=0; y<=9; ++y) {
                    int cnt = (l[i-1][x*10+y] * r[i+1][y*10+x]) % M;
                    ans = (ans + cnt) % M;
                }
        return ans;
    }
};