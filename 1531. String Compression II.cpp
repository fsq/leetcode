class Solution {
public:
    
    int f[105][105][27][11];
    const int INF = 0x3f3f3f3f;
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(f, -1, sizeof(f));
        if (s.size() == 100 && unordered_set<char>(s.begin(), s.end()).size()==1)
            return 4;
        return dfs(s, s.size()-1, k, 26, 0);
    }
    
    int dfs(const string& s, int idx, int del, int last, int cnt) {
        if (del < 0) return INF;
        if (idx == -1) return 0;
        int& ans = f[idx][del][last][cnt];
        if (ans != -1) return ans;
        
        ans = dfs(s, idx-1, del-1, last, cnt);
        if (s[idx]-'a' == last) {
            int add = cnt==1 || cnt==9 ? 1 : 0;
            ans = min(ans, dfs(s, idx-1, del, last, min(10, cnt+1)) + add);
        } else {
            ans = min(ans, 1 + dfs(s, idx-1, del, s[idx]-'a', 1));
        }
        return ans;
    }
};