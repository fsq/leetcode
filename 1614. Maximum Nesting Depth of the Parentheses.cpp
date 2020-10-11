class Solution {
public:
    int maxDepth(string s) {
        int dp = 0, ans = 0;
        for (auto c : s) {
            if (c=='(')
                ++dp;
            else if (c==')')
                --dp;
            ans = max(ans, dp);
        }
        return ans;
    }
};