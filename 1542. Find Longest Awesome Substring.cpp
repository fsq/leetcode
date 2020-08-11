class Solution {
public:
    int longestAwesome(string s) {
        vector<int> pre(1025, INT_MIN);
        pre[0] = -1;
        int ans = 0, sum = 0;
        for (int i=0; i<s.size(); ++i) {
            sum ^= 1 << (s[i] - '0');
            if (pre[sum] != INT_MIN)
                ans = max(ans, i - pre[sum]);
            else
                pre[sum] = i;

            for (int j=0; j<=9; ++j) {
                int t = sum ^ (1 << j);
                if (pre[t] != INT_MIN)
                    ans = max(ans, i - pre[t]);
            }
        }
        return ans;
    }
};