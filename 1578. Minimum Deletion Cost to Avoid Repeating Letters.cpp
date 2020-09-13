class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        for (int i=0, j; i+1<s.size(); i=j) 
            if (s[i]==s[i+1]) {
                int tot = 0, mx = 0;
                for (j=i; j<s.size() && s[j]==s[i]; ++j) {
                    tot += cost[j];
                    mx = max(mx, cost[j]);
                }
                ans += tot - mx;
            } else 
                j = i + 1;
        return ans;
    }
};