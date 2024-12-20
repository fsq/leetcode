unordered_set<int> st;

class Solution {
public:
    vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

    void Prime() {
        vector<int> vis(1000000);
        for (long long i=2; i<vis.size(); ++i) {
            if (!vis[i]) {
                st.insert(i);
                for (auto j=i*i; j<vis.size(); j+=i) {
                    vis[j] = true;
                }
            }
        }
    }

    int mostFrequentPrime(vector<vector<int>>& a) {
        if (st.empty()) {
            Prime();
        }
        int n = a.size(), m = a[0].size();
        unordered_map<int, int> f;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                for (int dir=0; dir<8; ++dir) {
                    int v=0, tx=i, ty=j;
                    do {
                        v = v*10 + a[tx][ty];
                        if (v>10 && st.count(v)) ++f[v];
                        tx += dx[dir];
                        ty += dy[dir];
                    } while (tx>=0 && tx<n && ty>=0 && ty<m);
                }
            }
        int ans=-1, mf=0;
        for (auto& pr : f)
            if (pr.second>mf || pr.second==mf && pr.first>ans) {
                ans = pr.first;
                mf = pr.second;
            }
        return ans;
    }
};