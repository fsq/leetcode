class Solution {
public:
    
    int rm;
    long long ans = 0;
    
    long long tok(string s, int k) {
        long long b=1, x=0;
        for (int i=0; i<s.size(); ++i) {
            x += b * (s[i]-'0');
            b *= k;
        }
        auto t = to_string(x);
        for (int i=0, j=t.size()-1; i<j; ++i,--j)
            if (t[i] != t[j])
                return 0;
        --rm;
        return x;
    }
    
    void dfs(int k, int d, string& s, int i, int j) {
        if (!rm) return;
        if (i > j) {
            ans += tok(s, k);
            return;
        }
        for (int x=(i==0 ? 1 : 0); x<k; ++x) {
            s[i] = s[j] = '0' + x;
            dfs(k, d, s, i+1, j-1);
        }
    }
    
    long long kMirror(int k, int n) {
        rm = n;
        for (int d=1; rm; ++d) {
            auto s = string(d, ' ');
            dfs(k, d, s, 0, d-1);            
        }
        return ans;
    }
};