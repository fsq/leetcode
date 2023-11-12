class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0;
        for (int i=0, j=0; i<s.size(); ) {
            int cnt = 0;
            while (i<s.size() && s[i]=='0') ++i, ++cnt;
            for (j=i; j<s.size() && s[j]=='1'; ++j);
            ans = max(ans, min(cnt, j-i)*2);
            i = j;
        }
        return ans;
    }
};