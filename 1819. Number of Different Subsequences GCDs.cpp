class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& a) {
        int mx = *max_element(a.begin(), a.end());
        
        vector<int> vis(mx+1);
        for (auto x : a) vis[x] = true;
        
        int ans = 0;
        for (int x=1; x<=mx; ++x) {
            int g = -1;
            for (int s=x; s<=mx; s+=x)
                if (vis[s]) {
                    g = g==-1 ? s : gcd(s, g);
                }
            if (g==x) ++ans;
        }
        return ans;
    }
};