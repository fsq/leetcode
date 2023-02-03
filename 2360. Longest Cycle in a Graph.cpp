class Solution {
public:
    int longestCycle(vector<int>& e) {
        int n = e.size(), ans = -1, ind = 1;
        vector<int> f(n);
        for (int i=0; i<n; ++i)
            if (!f[i]) {
                int start = ind;
                for (int x=i; x!=-1 && !f[x]; x=e[x]) {
                    f[x] = ind++;
                    if (e[x]!=-1 && f[e[x]] >= start) {
                        ans = max(ans, f[x]-f[e[x]]+1);
                        break;
                    }
                }
            }
        return ans;
    }
};