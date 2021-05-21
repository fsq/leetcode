class Solution {
public:
    int minSideJumps(vector<int>& a) {
        int n = a.size() - 1;
        vector<int> f = {1, 0, 1};
        for (int i=1; i<=n; ++i) {
            if (a[i]) f[a[i]-1] = 0x3f3f3f3f;
            for (int j=0; j<3; ++j)
                if (j+1 != a[i])
                    f[j] = min(f[j], min(f[(j+1)%3], f[(j+2)%3]) + 1);
        }
        return min(min(f[1], f[2]), f[0]);
    }
};