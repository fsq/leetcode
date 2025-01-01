class Solution {
public:
    int f[10001][11];
    int s[10001][17];

    int minimumValueSum(vector<int>& a, vector<int>& v) {
        int n = a.size();
        memset(f, -1, sizeof(f));
        memset(s, 0, sizeof(s));
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<17; ++j) 
                s[i][j] = s[i-1][j] + (a[i-1] >> j & 1);
        }
        auto sum = [&](int l, int r) {
            int x = 0;
            for (int j=0; j<17; ++j)
                if (s[r][j]-s[l-1][j] == r-l+1)
                    x |= 1 << j;
            return x;
        };
        f[0][0] = 0;
        for (int s=-1,i=1; i<=n; ++i) {
            s &= a[i-1];
            if (s == v[0]) f[i][1] = a[i-1];
        }
        
        // f[i][k] = a[i] + min(f[j][k-1]), where a[j+1] &.. a[i] == target
        for (int k=2; k<=v.size(); ++k) {
            int target = v[k-1];
            int l=0,r=0; 
            // r: leftmost index such that a[r+1]..a[i] > target
            // l: leftmost index such that a[l+1]..a[i] >= target
            // [l, r): indices such that a[j+1]..a[i]==target
            multiset<int> st; // Can improve with mono queue
            for (int i=1; i<=n; ++i) {
                while (r<i && ((sum(r+1, i)&target) < target || sum(r+1, i)==target)) {
                    if (f[r][k-1]!=-1) {
                        st.insert(f[r][k-1]);
                    }
                    ++r;
                }
                while (l<r && (sum(l+1, i)&target) < target) {
                    if (f[l][k-1]!=-1) {
                        st.erase(st.find(f[l][k-1]));
                    }
                    ++l;
                }
                if (st.size()) {
                    f[i][k] = *st.begin() + a[i-1];
                }
            }
        }
        return f[n][v.size()];
    }
};