class Solution {
public:
    vector<int> fa;
    
    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        int nq = q.size();
        for (int i=0; i<nq; ++i)
            q[i].push_back(i);
        sort(q.begin(), q.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        sort(e.begin(), e.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        vector<bool> ans(nq);
        for (int j=0,i=0; i<q.size(); ++i) {
            while (j<e.size() && e[j][2]<q[i][2]) {
                int fx=find(e[j][0]), fy=find(e[j][1]);
                if (fx != fy) {
                    fa[fx] = fy;
                }
                ++j;
            }
            ans[q[i][3]] = find(q[i][0]) == find(q[i][1]);
        }
        return ans;
    }
};