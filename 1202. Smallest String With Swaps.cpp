class Solution {
public:
    vector<int> fa;
    
    int find(int x) {
        return fa[x]==x ? x : fa[x] = find(fa[x]);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pr) {
        int n = s.size();
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        for (auto& p : pr) {
            int fx = find(p[0]), fy = find(p[1]);
            if (fx != fy) 
                fa[fx] = fy;
        }
        unordered_map<int, vector<int>> cnt;
        for (int i=0; i<n; ++i) {
            int f = find(i);
            if (!cnt.count(f))
                cnt[f] = vector<int>(26);
            ++cnt[f][s[i]-'a'];
        }
        unordered_map<int, int> p;
        for (int i=0; i<n; ++i) {
            int& pf = p[fa[i]];
            vector<int>& c = cnt[fa[i]];
            while (c[pf]==0) ++pf;
            s[i] = pf + 'a';
            --c[pf];
        }
        return s;
    }
};