class Solution {
public:
    int maxOperations(string s) {
        int prev = -1;
        int cnt = 0;
        int ans = 0;
        for (int i=0; i<s.size(); ++i)
            if (s[i] == '1') {
                if (prev+1 < i) ans += cnt;
                prev = i;
                ++cnt;
            }
        if (s.back() == '0') ans += cnt;
        return ans;
    }
};