class Solution {
public:
    unordered_map<int, int> cnt, fa;
    
    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    
    void connect(int a, int b) {
        int x=find(a), y=find(b);
        if (x != y) {
            fa[x] = y;
            cnt[y] += cnt[x];
        }
    }
    
    vector<int> groupStrings(vector<string>& words) {
        for (auto& s : words) {
            int m = 0;
            for (auto c : s) m |= 1 << (c-'a');
            if (!fa.count(m)) {
                fa[m] = m;
            }
            ++cnt[m];
        }
        for (auto& pr :fa) {
            int m = pr.first, f = pr.second;
            for (int i=0; i<26; ++i)
                if (!(m & (1<<i))) {
                    int t = m | (1<<i);
                    if (fa.count(t)) {
                        connect(m, t);
                    }
                } else {
                    int t = m ^ (1<<i);
                    if (fa.count(t)) {
                        connect(m, t);
                    }
                    for (int j=0; j<26; ++j) {
                        int nt = t | (1 << j);
                        if (nt!=m && fa.count(nt)) {
                            connect(m, nt);
                        }
                    }
                }
        }
        vector<int> ans(2);
        for (auto& pr : fa) 
            if (pr.first == pr.second) {
                ++ans[0];
                ans[1] = max(ans[1], cnt[pr.first]);
            }
        return ans;
        
    }
};