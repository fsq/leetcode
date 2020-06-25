class Solution {
public:
    vector<int> fa;
    int n;
    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    
    int krus(vector<vector<int>>& e, int ban, int force) {
        int ans = 0;
        fa = vector<int>(n);
        iota(fa.begin(), fa.end(), 0);
        int cc = n;
        if (force >= 0) {
            fa[e[force][0]] = e[force][1];
            ans += e[force][2];
            --cc;
        }
        for (int j=0; j<e.size(); ++j) 
            if (j != ban) {
                int fx = find(e[j][0]), fy = find(e[j][1]);
                if (fx != fy) {
                    fa[fx] = fy;
                    ans += e[j][2];
                    --cc;
                }
            }
        return cc==1 ? ans : INT_MAX;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n_, vector<vector<int>>& eg) {
        n = n_;
        for (int i=0; i<eg.size(); ++i)
            eg[i].push_back(i);
        sort(eg.begin(), eg.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2]; 
        });

        int mst = krus(eg, -1, -1);
        vector<int> ce, pce;
        for (int i=0; i<eg.size(); ++i) {
            int m1 = krus(eg, i, -1);
            if (m1 > mst)
                ce.push_back(eg[i][3]);
            else {
                int m2 = krus(eg, -1, i);
                if (m2==mst)
                    pce.push_back(eg[i][3]);
            }
            
        }
        return {ce, pce};
    }
};