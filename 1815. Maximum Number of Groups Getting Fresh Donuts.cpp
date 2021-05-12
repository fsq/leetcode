class Solution {
public:
    
    map<vector<int>, int> m;
    
    int dfs(vector<int>& a, int rm, int b, int res) {
        if (rm == 0) return 0;
        if (m.count(a)) return m[a];
        int& ans = m[a];
        for (int i=1; i<b; ++i) 
            if (a[i]) {
                --a[i];
                ans = max(ans, dfs(a, rm-1, b, (res+i)%b) + (res==0));
                ++a[i];
            }
        return ans;
    }
    
    int maxHappyGroups(int b, vector<int>& a) {
        int ans = 0;
        vector<int> res(10);
        for (auto x : a) {
            if (x % b == 0)
                ++ans;
            else 
                ++res[x % b];
        }
        for (int i=1; i<=b-i; ++i) {
            int c = b - i;
            int take = i==c ? res[c]/2 : min(res[i], res[c]);
            res[i] -= take;
            res[c] -= take;
            ans += take;
        }
        return dfs(res, a.size()-ans, b, 0) + ans;
        
    }
};