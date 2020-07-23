class Solution {
public:
    
    int f[100001][17];
    
    int query(int l, int r) {
        int len = r - l + 1;
        int p = log(len)/log(2);
        return f[l][p] & f[r-(1<<p)+1][p];
    }
    
    int closestToTarget(vector<int>& a, int target) {
        int n = a.size();
        for (int i=0; i<n; ++i)
            f[i][0] = a[i];
        for (int j=1; (1<<j)<=a.size(); ++j) 
            for (int i=0; i+(1<<j)<=a.size(); ++i) {
                f[i][j] = f[i][j-1] & f[i+(1<<(j-1))][j-1];
            }
        int ans = abs(a[0] - target);
        for (int l=0, r=0; l<a.size(); ++l) {
            r = max(r, l);
            int s = query(l, min(n-1, r));
            while (r < a.size() && s >= target) {
                ans = min(ans, s - target);
                s &= a[++r];
            }
            if (r < a.size()) 
                ans = min(ans, target - s);
            if (ans == 0) break;
        }
        return ans;
    }
};