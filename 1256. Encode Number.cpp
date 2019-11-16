class Solution {
public:
    string encode(int x) {
        if (x==0) return "";
        int n = 1;
        while ((1<<n) <= x+1) ++n;
        --n;
        string ans(n, '0');
        x -= (1<<n) - 1;
        for (int i=0; x; ++i, x>>=1)
            ans[i] += x & 1;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};