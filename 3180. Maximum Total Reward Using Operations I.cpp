class Solution {
public:
    int ans = 0;
    int f[2001][2001];

    int dfs(vector<int>& a, int i, int cap) {
        if (i==a.size()) {
            return 0;
        }
        int& ans = f[i][cap];
        if (ans != -1) return ans;
        
        if (a[i] <= cap) {
            ans = a[i] + dfs(a, i+1, min(cap-a[i], a[i]-1));
        }
        ans = max(ans, dfs(a, i+1, cap));
        return ans;
    }

    int maxTotalReward(vector<int>& a) {
        memset(f, -1, sizeof(f));
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            ans = max(ans, a[i] + dfs(a, i+1, a[i]-1));
        }
        return ans;
    }
};