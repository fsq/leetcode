class Solution {
public:
    
    unordered_map<string, int> ans;
    
    inline int cost(int i) {
        return i==0 ? 1 : i-1;
    }
    
    int dp(int i, int x, int n) {
        string key = to_string(i) + "," + to_string(n);
        if (ans.count(key)) return ans[key];
        if (n==0) return 0;
        if (i>=50) return 1e9;
        int a = n % x;
        int t1 = 1 + a-1 + cost(i) * a + dp(i+1, x, (n-a)/x);
        int t2 = 1 + (x-a-1) + cost(i) * (x-a) + dp(i+1, x, (n-a)/x+1);
        return ans[key] = min(t1, t2);
    }
    
    int leastOpsExpressTarget(int x, int target) {
        
        return dp(0, x, target) - 1;
        
    }
};