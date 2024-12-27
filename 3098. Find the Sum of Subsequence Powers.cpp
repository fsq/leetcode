class Solution {
public:
    const int M = 1000000007;

    long long f[51][51][2];

    int sumOfPowers(vector<int>& a, int kk) {
        sort(a.begin(), a.end());
        int n = a.size();
        unordered_set<int> st;
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j)
                st.insert(a[j] - a[i]);
        long long ans = 0;
        for (auto gap: st) {
            memset(f, 0, sizeof(f));
            f[0][1][0] = 1;
            for (int i=1; i<n; ++i) {
                f[i][1][0] = 1;
                for (int k=2; k<=kk && k<=(i+1); ++k) {
                    for (int j=0; j<i && a[i]-a[j]>=gap; ++j) {
                        if (a[i]-a[j] > gap) {
                            f[i][k][0] += f[j][k-1][0];
                            f[i][k][1] += f[j][k-1][1];
                        } else {
                            f[i][k][1] += f[j][k-1][0] + f[j][k-1][1];
                        }
                        f[i][k][0] %= M;
                        f[i][k][1] %= M;
                    }
                }
                ans = (ans + gap*f[i][kk][1]) % M;
            }
        }
        return ans;
    }
};