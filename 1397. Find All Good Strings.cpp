class Solution {
public:
    
    int jp[51][128];
    int g[501][51];
    const int M = 1e9 + 7;
    long long ans = 0;
    string from, to, e;
    
    int dfs(int i, int pre/*前接了evil的前pre个*/, int bound) {
        if (i==from.size()) return 1;
        int n = from.size() - i;
        long long ans = 0;
        char f0=bound==1 ? 'a' : from[i], t0=bound==0 ? 'z' : to[i];
        
        for (char now=f0; now<=t0; ++now) {
            int j;
            if (now==e[pre]) {
                j = pre + 1;
                if (j==e.size()) continue;
            } else 
                j = jp[pre][now];
            if (f0==t0) return dfs(i+1, j, bound);
            
            if (bound==-1){
                if (now==f0 || now==t0)
                    ans += dfs(i+1, j, now==t0 ? 1 : 0);
                else 
                    ans += g[n-1][j];                    
            } else if (bound==0 && now==f0 || bound==1 && now==t0)
                ans += dfs(i+1, j, bound);
            else 
                ans += g[n-1][j];
        }
        return ans % M;
    }
    
    int findGoodStrings(int n, string s1, string s2, string evil) {
        from = s1, to = s2, e = evil;
        
        // 前缀是evil的前i个，如果现在接上j，kmp会match的最长前缀长度
        memset(jp, 0, sizeof(jp));
        
        vector<int> kmp(e.size()+1);
        for (int i=1; i<e.size(); ++i) {
            for (char now='a'; now<='z'; ++now) {
                int j = kmp[i-1];
                while (j>0 && now!=e[j]) j = kmp[j-1];
                if (now==e[i]) kmp[i] = j + (now==e[j]);
                jp[i][now] = j + (now==e[j]);
            }
        }
        
        // g[i][j]: 如果前接evil的前j个，长度为i的合法字符串有多少
        memset(g, 0, sizeof(g));
        for (int j=0; j<e.size(); ++j) g[0][j] = 1;
        for (int i=1; i<n; ++i)
            for (int j=0; j<e.size(); ++j) {
                for (char now='a'; now<='z'; ++now)
                    if (now==e[j]) {
                        if (j+1==e.size()) continue;
                        g[i][j] = (g[i][j] + g[i-1][j+1]) % M;
                    } else 
                        g[i][j] = (g[i][j] + g[i-1][jp[j][now]]) % M;
            }
        
        return dfs(0, 0, -1);
    }
};