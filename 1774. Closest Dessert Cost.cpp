class Solution {
public:
    
    void dfs(vector<int>& b, unordered_set<int>& cb, int i, int s) {
        if (i==b.size()) {
            cb.insert(s);
        } else {
            dfs(b, cb, i+1, s);
            dfs(b, cb, i+1, s+b[i]);
            dfs(b, cb, i+1, s+b[i]*2);
        }
    }
    
    int closestCost(vector<int>& a, vector<int>& b, int target) {
        unordered_set<int> cb;
        dfs(b, cb, 0, 0);
        int ans = a[0];
        for (auto x : a)
            for (auto y : cb) {
                int s = x + y;
                if (abs(s-target) < abs(ans-target) || abs(s-target)==abs(ans-target) && s < ans) {
                    ans = s;       
                }
            }
        return ans;
    }
};