class Solution {
public:
    int d[201][201];
    const int INF = 0x3f3f3f3f;

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        memset(d, 0x3f,sizeof(d));
        unordered_map<string, int> si;
        vector<string> is;
        int sn = 0;
        for (auto& s : original) {
            si[s] = sn++;
            is.push_back(s);
        }
        for (auto& s : changed)
            if (!si.count(s)) {
                si[s] = sn++;
                is.push_back(s);
            }
        for (int i=0; i<original.size(); ++i) {
            auto& ds = d[si[original[i]]][si[changed[i]]];
            ds = min(ds, cost[i]);
        }
        for (int i=0; i<sn; ++i) d[i][i] = 0;
        for (int k=0; k<sn; ++k)
            for (int i=0; i<sn; ++i)
                for (int j=0; j<sn; ++j)
                    if (i!=k && k!=j)
                        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        
        vector<vector<int>> mi(source.size()), mj(source.size());
        for (int i=0; i<source.size(); ++i)
            for (int j=0; j<is.size(); ++j) {
                if (i+1>=is[j].size()) {
                    if (equal(is[j].begin(), is[j].end(), source.begin()+i+1-is[j].size())) mi[i].push_back(j);
                    if (equal(is[j].begin(), is[j].end(), target.begin()+i+1-is[j].size())) mj[i].push_back(j);
                }
            }
        // Optmz: For substring length, compare only once.
        vector<long long> f(source.size()+1, LLONG_MAX);
        f[0] = 0;
        for (int i=1; i<=source.size(); ++i) {
            if (source[i-1]==target[i-1]) f[i] = f[i-1];
            for (auto x: mi[i-1])
                if (i>=is[x].size() && f[i-is[x].size()]!=LLONG_MAX)
                    for (auto y: mj[i-1])
                        if (is[x].size() == is[y].size()) {
                            int dis = d[x][y];
                            if (dis == INF) continue;
                            f[i] = min(f[i], f[i-is[x].size()]+dis);
                        }
        }
        return f.back()==LLONG_MAX ? -1 : f.back();
    }
};